#include "framework.h"
#include "Barrel.h"
#include "Ball.h"
#include "Cannon.h"

Cannon::Cannon()
{
	_body = make_shared<CircleCollider>(Vector(350, 350), 50);
	//_barrel = make_shared<Line>(_body->Center(), _body->Center() + Vector(150, 0));
	_barrel = make_shared<Barrel>();
	for (int i = 0; i < _poolCount; i++)
	{
		_balls.push_back(make_shared<Ball>());
	}
	
}

Cannon::~Cannon()
{
}

void Cannon::Update()
{
	_body->Update();
	_barrel->Update();
	for (auto b : _balls)
	{
		b->Update();
	}

	InputMove();
	InputBarrelRotation();
	InputFire();
	// 총신 조정
}

void Cannon::Render(HDC hdc)
{
	_barrel->Render(hdc);
	_body->Render(hdc);
	for (auto b : _balls)
	{
		b->Render(hdc);
	}
}

void Cannon::Fire()
{
	if (_shootStandby == true)
	{
		_shootStandby = false;
		auto iter = std::find_if(_balls.begin(), _balls.end(), [](const shared_ptr<Ball>& ball) -> bool {
			if (ball->IsFired() == false)
				return true;
			return false;
			});
		if (iter == _balls.end()) return;
		(*iter)->Fire(_barrel->GetMuzzle(), _barrel->GetDirection());
	}
}

void Cannon::InputMove()
{
	if (GetAsyncKeyState(VK_LEFT) & 0x8001)
		_body->Center()._x -= 3;

	if (GetAsyncKeyState(VK_RIGHT) & 0x8001)
		_body->Center()._x += 3;

	
}

void Cannon::InputBarrelRotation()
{
	//if (GetAsyncKeyState(VK_UP) & 0x8001)
	//	_angle += 3;
	//if (GetAsyncKeyState(VK_DOWN) & 0x8001)
	//	_angle -= 3;

	////_barrel->_start = _body->Center();
	//float Radian = _angle * (PI / 180);

	//float sinTheta = std::sinf(Radian);
	//float cosTheta = std::cosf(Radian);

	////W_barrel->_end = _body->Center() + Vector(cosTheta * 150, -sinTheta * 150);
	// TODO : 방향키 위로 누르면 총신의 각도가 +가 되게
	// 방향키 아래를 누르면 총신의 각도가 -가 되게하기.

	_barrel->SetDirection((mousePos - _body->Center()).NormalVector());
}

void Cannon::InputFire()
{
	if (GetAsyncKeyState(VK_SPACE) & 0x8001)
		Fire();
	else
		_shootStandby = true;
}


