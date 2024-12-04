#include "framework.h"
#include "RectangleCollider.h"

RectangleCollider::RectangleCollider(Vector center, Vector size, float angle)
	: _halfSize(size * 0.5f)
{
	_center = center;
	_type = RECT;
	AngleToDir(angle);
}

void RectangleCollider::Update()
{
	SetAngle();
}

void RectangleCollider::Render(HDC hdc)
{
	MoveToEx(hdc, _topLeft._x, _topLeft._y, nullptr);
	LineTo(hdc, _topRight._x, _topRight._y);
	LineTo(hdc, _bottomRight._x, _bottomRight._y);
	LineTo(hdc, _bottomLeft._x, _bottomLeft._y);
	LineTo(hdc, _topLeft._x, _topLeft._y);
}

bool RectangleCollider::IsCollision(const Vector& pos) const
{
	return false;
}

bool RectangleCollider::IsCollision(shared_ptr<CircleCollider> other) const
{
	return false;
}

bool RectangleCollider::IsCollision(shared_ptr<RectCollider> other) const
{
	return false;
}

void RectangleCollider::AngleToDir(float angle)
{
	float angleRadians = angle * (PI / 180.0f);
	_direction = Vector(std::cos(angleRadians), std::sin(angleRadians)).Normalize();
}

void RectangleCollider::SetAngle()
{
	_topLeft = _center + Vector(_direction._x * -_halfSize._x - _direction._y * -_halfSize._y, _direction._y * -_halfSize._x + _direction._x * -_halfSize._y);
	_topRight = _center + Vector(_direction._x * _halfSize._x - _direction._y * -_halfSize._y, _direction._y * _halfSize._x + _direction._x * -_halfSize._y);
	_bottomRight = _center + Vector(_direction._x * _halfSize._x - _direction._y * _halfSize._y, _direction._y * _halfSize._x + _direction._x * _halfSize._y);
	_bottomLeft = _center + Vector(_direction._x * -_halfSize._x - _direction._y * _halfSize._y, _direction._y * -_halfSize._x + _direction._x * _halfSize._y);
}
