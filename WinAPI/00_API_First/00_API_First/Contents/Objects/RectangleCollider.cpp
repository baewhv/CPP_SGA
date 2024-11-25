#include "framework.h"
#include "RectangleCollider.h"

RectangleCollider::RectangleCollider(Vector center, Vector size, float angle)
	: _halfSize(size * 0.5f)
	, _angle(angle)
{
	_center = center;



	
}

void RectangleCollider::Update()
{
	SetAnglePoint();
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

void RectangleCollider::SetAnglePoint()
{
	float angleRadians = _angle * (PI / 180.0f);

	// 끝점에서 시작점을 뺀 상대 좌표 계산

	// 회전 변환 적용
	float cosTheta = std::cos(angleRadians);
	float sinTheta = std::sin(angleRadians);

	_topLeft = Vector(_center._x + cosTheta * -_halfSize._x - sinTheta * -_halfSize._y, _center._y + sinTheta * -_halfSize._x + cosTheta * -_halfSize._y);
	_topRight = Vector(_center._x + cosTheta * _halfSize._x - sinTheta * -_halfSize._y, _center._y + sinTheta * _halfSize._x + cosTheta * -_halfSize._y);
	_bottomRight = Vector(_center._x + cosTheta * _halfSize._x - sinTheta * _halfSize._y, _center._y + sinTheta * _halfSize._x + cosTheta * _halfSize._y);
	_bottomLeft = Vector(_center._x + cosTheta * -_halfSize._x - sinTheta * _halfSize._y, _center._y + sinTheta * -_halfSize._x + cosTheta * _halfSize._y);
}
