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
	auto rect = dynamic_pointer_cast<RectCollider>(collider);
	auto circle = dynamic_pointer_cast<CircleCollider>(collider);

	if (rect != nullptr)
	{
		return shared_from_this()->IsCollision(rect);
	}
	else
	{

	}
	return false;
}

bool Collider::IsCollision(const Vector& pos) const
{
	return false;
}
bool Collider::IsCollision(shared_ptr<RectCollider> other) const
{
	return false;
}