#include "framework.h"
#include "BoxCollider.h"

BoxCollider::BoxCollider(Vector center, float width, float height)
	:_center(center), _width(width), _height(height)
{
}

BoxCollider::~BoxCollider()
{
}

void BoxCollider::Update()
{
}

void BoxCollider::Render(HDC hdc)
{
	Rectangle(hdc, _center._x - _width / 2,
		_center._y - _height / 2,
		_center._x + _width / 2,
		_center._y + _height / 2
	);
}
