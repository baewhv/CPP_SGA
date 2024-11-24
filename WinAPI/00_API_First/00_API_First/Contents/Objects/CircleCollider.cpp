#include "framework.h"
#include "CircleCollider.h"

CircleCollider::CircleCollider(Vector center, float radius)
	:_radius(radius)
{
	_center = center;
	_colors[0] = CreatePen(3, 3, RED);
	_colors[1] = CreatePen(3, 3, GREEN);
}

CircleCollider::~CircleCollider()
{
}

void CircleCollider::Update()
{
	//TODO
}

void CircleCollider::Render(HDC hdc)
{
	SelectObject(hdc, _colors[_curColor]);
	Ellipse(hdc, 
		_center._x - _radius,
		_center._y - _radius,
		_center._x + _radius,
		_center._y + _radius);
}

bool CircleCollider::IsCollision(const Vector& pos) const
{
	float a = (pos - _center).Length();
	return a < _radius;
}

bool CircleCollider::IsCollision(shared_ptr<CircleCollider> other) const
{
	float a = (other->Center() - _center).Length();
	float b = other->Radius() + _radius;
	return a < b;
}
bool CircleCollider::IsCollision(shared_ptr<RectCollider> other) const
{
	return false;
}