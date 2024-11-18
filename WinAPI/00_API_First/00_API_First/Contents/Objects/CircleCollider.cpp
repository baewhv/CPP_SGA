#include "framework.h"
#include "CircleCollider.h"

CircleCollider::CircleCollider(Vector center, float radius)
	:_center(center)
	,_radius(radius)
{
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
	Ellipse(hdc, 
		_center._x - _radius,
		_center._y - _radius,
		_center._x + _radius,
		_center._y + _radius);
}
