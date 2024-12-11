#pragma once
class Cannon;

class Ball
{
public:
	Ball();
	~Ball();

	void Update();
	void Render(HDC hdc);

	
	void SetPosition(Vector pos) { _ball->Center() = pos; }
	void SetDirection(Vector dir) { _direction = dir; }
	void SetSpeed(float spd = 5.0f) { _speed = spd; }
	bool IsFired() { return _isFired; }

	void Fire(Vector pos, Vector dir);
	bool IsOut();
	void SetCannon(shared_ptr<Cannon> c) { myCannon = c; }
	
private:
	shared_ptr<CircleCollider> _ball;
	Vector _direction;
	float _speed = 5;
	bool _isFired = false;
	bool _isGravity = true;
	float _gravity;

	weak_ptr<Cannon> myCannon;
};

