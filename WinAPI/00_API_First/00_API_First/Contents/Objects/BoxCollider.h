#pragma once
class BoxCollider
{
public:
	BoxCollider(Vector center, float width, float height);
	~BoxCollider();

	void Update();
	void Render(HDC hdc);

private:
	Vector _center;
	float _width;
	float _height;
};

