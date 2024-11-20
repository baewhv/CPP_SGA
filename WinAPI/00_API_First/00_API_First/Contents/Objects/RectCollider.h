#pragma once
class RectCollider
{
public:
	RectCollider(Vector center, Vector size);
	~RectCollider();

	int Left() { return _center._x - _halfSize._x; }
	int Right() { return _center._x + _halfSize._x; }
	int Top() { return _center._y - _halfSize._y; }
	int Bottom() { return _center._y + _halfSize._y; }

	Vector& Center() { return _center; }

	void Update();
	void Render(HDC hdc);

private:
	Vector _center;
	Vector _halfSize;
};

