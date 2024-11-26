#include "framework.h"
#include "RectCollider.h"

RectCollider::RectCollider(Vector center, Vector size)
	: _halfSize(size * 0.5f)
{
	_center = center;
	_colors[0] = CreatePen(3, 3, RED);
	_colors[1] = CreatePen(3, 3, GREEN);
	_type = RECT;
}

RectCollider::~RectCollider()
{
}

void RectCollider::Update()
{
}

void RectCollider::Render(HDC hdc)
{
	SelectObject(hdc, _colors[_curColor]);
	Rectangle(hdc, _center._x - _halfSize._x,
		_center._y - _halfSize._y,
		_center._x + _halfSize._x,
		_center._y + _halfSize._y
	);
}

bool RectCollider::IsCollision(const Vector& pos) const
{
	if (Left() < pos._x &&
		Right() > pos._x &&
		Top() < pos._y &&
		Bottom() > pos._y)
		return true;
	return false;
}
//bool RectCollider::IsCollision(shared_ptr<Collider> other) const
//{
//	switch (other->getType())
//	{
//	case Collider::NONE:
//
//		break;
//	case Collider::CIRCLE:
//	{
//		auto circle = dynamic_pointer_cast<CircleCollider>(other);
//		if (circle != nullptr)
//			return IsCollision(circle);
//		break;
//	}
//	case Collider::RECT:
//	{
//		auto rect = dynamic_pointer_cast<RectCollider>(other);
//		return IsCollision(rect);
//	}
//	default:
//		break;
//	}
//	return false;
//}

bool RectCollider::IsCollision(shared_ptr<CircleCollider> other) const
{
	//obb
	OBB_INFO a = GetOBB();
	//¡ﬂΩ… ≥¢∏Æ ø¨∞·µ» ∫§≈Õ.fp
	Vector aTob = other->Center() - a.position;


	float d = sqrtf(a.length[0] * a.length[0] + a.length[1] * a.length[1]) + other->Radius();
	if (d < aTob.Length())
		return false;

	//∞¢ ∫Ø¿« ≥Î∏ª∫§≈Õ π◊ ∫§≈Õ
	Vector normal_ea1 = a.Direction[0].NormalVector();
	Vector ea1 = a.Direction[0];
	Vector normal_ea2 = a.Direction[1].NormalVector();
	Vector ea2 = a.Direction[1];

	float length = abs(normal_ea1.Dot(aTob));
	float lengthB = other->Radius();
	float lengthA = a.length[0];
	if (length > lengthB + lengthA)
		return false;

	length = abs(normal_ea2.Dot(aTob));
	lengthB = other->Radius();
	lengthA = a.length[1];
	if (length > lengthB + lengthA)
		return false;

	return true;
}

bool RectCollider::IsCollision(shared_ptr<RectCollider> other) const
{
	//aabb
	//float bigLeft = max(Left(), other->Left());
	//float smallRight = min(Right(), other->Right());
	//float bigBottom = max(Top(), other->Top());
	//float smallTop = min(Bottom(), othe0r->Bottom());

	//if (bigLeft - smallRight <= 0 && bigBottom - smallTop <= 0)
	//	return true;

	//obb
	OBB_INFO a = GetOBB();
	OBB_INFO b = other->GetOBB();

	//¡ﬂΩ… ≥¢∏Æ ø¨∞·µ» ∫§≈Õ.fp
	Vector aTob = b.position - a.position;

	//∞¢ ∫Ø¿« ≥Î∏ª∫§≈Õ π◊ ∫§≈Õ
	Vector normal_ea1 = a.Direction[0].NormalVector();
	Vector ea1 = a.Direction[0];
	Vector normal_ea2 = a.Direction[1].NormalVector();
	Vector ea2 = a.Direction[1];

	Vector normal_eb1 = b.Direction[0].NormalVector();
	Vector eb1 = b.Direction[0];
	Vector normal_eb2 = b.Direction[1].NormalVector();
	Vector eb2 = b.Direction[1];

	float length = abs(normal_ea1.Dot(aTob));
	float lengthB = SeparateAxis(normal_ea1, eb1, eb2);
	float lengthA = a.length[0];
	if (length > lengthB + lengthA)
		return false;

	length = abs(normal_ea2.Dot(aTob));
	lengthB = SeparateAxis(normal_ea2, eb1, eb2);
	lengthA = a.length[1];
	if (length > lengthB + lengthA)
		return false;

	length = abs(normal_eb1.Dot(aTob));
	lengthA = SeparateAxis(normal_eb1, ea1, ea2);
	lengthB = b.length[0];
	if (length > lengthB + lengthA)
		return false;

	length = abs(normal_eb2.Dot(aTob));
	lengthA = SeparateAxis(normal_eb2, ea1, ea2);
	lengthB = b.length[1];
	if (length > lengthB + lengthA)
		return false;

	return true;
}

RectCollider::OBB_INFO RectCollider::GetOBB() const
{
	OBB_INFO info;
	info.position = _center;

	info.Direction[0] = { _halfSize._x,0 };
	info.Direction[1] = { 0, _halfSize._y };

	info.length[0] = _halfSize._x;
	info.length[1] = _halfSize._y;

	return info;
}

//∫–∏Æ√‡
float RectCollider::SeparateAxis(Vector separate, Vector e1, Vector e2) const
{
	float r1 = abs(separate.Dot(e1));
	float r2 = abs(separate.Dot(e2));
	return r1+r2;
}
