#pragma once
class RectCollider : public Collider
{
public:
	RectCollider(Vector center, Vector size);
	~RectCollider();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	virtual bool IsCollision(const Vector& pos) const override;
	virtual bool IsCollision(shared_ptr<CircleCollider> other) const override;
	virtual bool IsCollision(shared_ptr<RectCollider> other) const override;

	Vector& HalfSize() { return _halfSize; }

	int Left() { return _center._x - _halfSize._x; }
	int Right() { return _center._x + _halfSize._x; }
	int Top() { return _center._y - _halfSize._y; }
	int Bottom() { return _center._y + _halfSize._y; }

private:

	Vector _halfSize;
};

