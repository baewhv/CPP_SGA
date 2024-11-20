#include "framework.h"
#include "RectCollider.h"

RectCollider::RectCollider(Vector center, Vector size)
	:_center(center), _halfSize(size * 0.5f)
{
}

RectCollider::~RectCollider()
{
}

void RectCollider::Update()
{
}

void RectCollider::Render(HDC hdc)
{
	Rectangle(hdc, _center._x - _halfSize._x,
		_center._y - _halfSize._y,
		_center._x + _halfSize._x,
		_center._y + _halfSize._y
	);
}
