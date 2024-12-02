#include "framework.h"
#include "Ball.h"

Ball::Ball()
{
	_ball = make_shared<CircleCollider>(Vector(10000,0), 15);
}

Ball::~Ball()
{
}

void Ball::Update()
{
	_ball->Update();
	//Åõ»çÃ¼ Projectile
	//_startPos _direction _speed
	_ball->Center() += _direction * _speed;

	
}

void Ball::Render(HDC hdc)
{
	_ball->Render(hdc);
}
