#pragma once
class CircleCollider;
class RectCollider;

class Collider : public enable_shared_from_this<Collider>
{
public:
	Collider();
	virtual ~Collider();

	virtual void Update() abstract;
	virtual void Render(HDC hdc) abstract;
	Vector& Center() { return _center; }

	void SetRed() { _curColor = 0; }
	void SetGreen() { _curColor = 1; }

	bool IsCollision(shared_ptr<Collider> collider) const;
	virtual bool IsCollision(const Vector& pos) const abstract;
	virtual bool IsCollision(shared_ptr<CircleCollider> other) const abstract;
	virtual bool IsCollision(shared_ptr<RectCollider> other) const abstract;

protected:
	int _curColor = 1;
	HPEN _colors[2];

	Vector _center;
};

