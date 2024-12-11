#include "framework.h"
#include "Ball.h"
#include "Cannon.h"

Ball::Ball() : _gravity(0.0f)
{
	_ball = make_shared<CircleCollider>(Vector(10000,0), 15);
}


Ball::~Ball()
{
}

void Ball::Update()
{
	
	if (_isFired == false) return;
	if (IsOut() == true)
	{
		_isFired = false;
		return;
	}
	_ball->Update();
	//투사체 Projectile
	//_startPos _direction _speed
	
	_ball->Center() += _direction * _speed; //등가속
	if (_isGravity == true)
	{
		_gravity += 0.1f;
		_ball->Center()._y += _gravity;
	}

}

void Ball::Render(HDC hdc)
{
	if (_isFired == false) return;
	_ball->Render(hdc);
}

void Ball::Fire(Vector pos, Vector dir)
{
	_isFired = true;
	_gravity = 0.0f;

	SetPosition(pos);
	SetDirection(dir);
}

bool Ball::IsOut()
{
	int x = _ball->Center()._x;
	int y = _ball->Center()._y;

	if (x > WIN_WIDTH || x < 0 || y > WIN_HEIGHT)
	{
		if (!myCannon.expired())
			myCannon.lock()->ShootCount()--;
		return true;
		
	}

	return false;
}


