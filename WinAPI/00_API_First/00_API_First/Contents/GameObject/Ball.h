#pragma once
class Ball
{
public:
	Ball();
	~Ball();

	void Update();
	void Render(HDC hdc);

	void SetPosition(Vector pos) { _ball->Center() = pos; }
	void SetDirection(Vector dir) { _direction = dir; }
	void SetSpeed(float spd) { _speed = spd; }
	bool& IsFired() { return _isFired; }

private:
	shared_ptr<CircleCollider> _ball;
	Vector _direction;
	float _speed;
	bool _isFired = false;
};

