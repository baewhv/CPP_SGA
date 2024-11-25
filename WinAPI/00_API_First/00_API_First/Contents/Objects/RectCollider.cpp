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
	if (_center._x - _halfSize._x < pos._x &&
		_center._x + _halfSize._x > pos._x &&
		_center._y - _halfSize._y < pos._y &&
		_center._y + _halfSize._y > pos._y)
		return true;
	return false;
}

bool RectCollider::IsCollision(shared_ptr<CircleCollider> other) const
{
	return false;
}

bool RectCollider::IsCollision(shared_ptr<RectCollider> other) const
{
	//aabb
	float bigLeft = max(_center._x - _halfSize._x, other->_center._x - other->_halfSize._x);
	float smallRight = min(_center._x + _halfSize._x, other->_center._x + other->_halfSize._x);
	float bigBottom = max(_center._y - _halfSize._y, other->_center._y - other->_halfSize._y);
	float smallTop = min(_center._y + _halfSize._y, other->_center._y + other->_halfSize._y);

	if (bigLeft - smallRight <= 0 && bigBottom - smallTop <= 0)
		return true;

	//obb


	return false;
}
