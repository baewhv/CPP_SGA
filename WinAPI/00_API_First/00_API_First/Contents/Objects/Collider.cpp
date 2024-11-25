#include "framework.h"
#include "Collider.h"

Collider::Collider()
{
}

Collider::~Collider()
{
}

bool Collider::IsCollision(shared_ptr<Collider> collider) const
{
	switch (collider->_type)
	{
	case Collider::NONE:
		return false;
	case Collider::CIRCLE:
	{
		auto circle = dynamic_pointer_cast<CircleCollider>(collider);
		if (circle != nullptr)
			return IsCollision(circle);
		break;
	}
	case Collider::RECT:
	{
		auto rect = dynamic_pointer_cast<RectCollider>(collider);
		return IsCollision(rect);
	}
	default:
		break;
	}

	return false;
}

