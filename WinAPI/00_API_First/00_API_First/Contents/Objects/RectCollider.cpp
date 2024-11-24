#include "framework.h"
#include "RectCollider.h"

RectCollider::RectCollider(Vector center, Vector size)
	: _halfSize(size * 0.5f)
{
	_center = center;
	_colors[0] = CreatePen(3, 3, RED);
	_colors[1] = CreatePen(3, 3, GREEN);
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
	return false;
}

bool RectCollider::IsCollision(shared_ptr<CircleCollider> other) const
{
	return false;
}
