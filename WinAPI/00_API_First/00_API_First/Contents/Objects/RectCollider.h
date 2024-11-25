#pragma once
class RectCollider : public Collider
{
public:
	struct OBB_INFO
	{
		Vector position;
		Vector Direction[2];
		float length[2];
	};
	RectCollider(Vector center, Vector size);
	~RectCollider();

	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	virtual bool IsCollision(const Vector& pos) const override;
	virtual bool IsCollision(shared_ptr<CircleCollider> other) const override;
	virtual bool IsCollision(shared_ptr<RectCollider> other) const override;

	Vector& HalfSize() { return _halfSize; }

	int Left() const { return _center._x - _halfSize._x; }
	int Right() const { return _center._x + _halfSize._x; }
	int Top() const { return _center._y - _halfSize._y; }
	int Bottom() const { return _center._y + _halfSize._y; }

	OBB_INFO GetOBB() const;
	float SeparateAxis(Vector separate, Vector e1, Vector e2) const;

private:

	Vector _halfSize;
};

