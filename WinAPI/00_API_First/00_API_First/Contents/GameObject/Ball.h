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
	bool IsFired() { return _isFired; }

	void Fire(Vector pos, Vector dir);
	bool IsOut();

private:
	shared_ptr<CircleCollider> _ball;
	Vector _direction;
	float _speed = 5;
	bool _isFired = false;
	bool _isGravity = true;
	float _gravity;
};

