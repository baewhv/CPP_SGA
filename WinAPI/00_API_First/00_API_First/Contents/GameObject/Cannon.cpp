#include "framework.h"
#include "Barrel.h"
#include "Ball.h"
#include "Cannon.h"

Cannon::Cannon()
{
	_body = make_shared<CircleCollider>(Vector(350, 350), 50);
	//_barrel = make_shared<Line>(_body->Center(), _body->Center() + Vector(150, 0));
	_barrel = make_shared<Barrel>();
	_ball = make_shared<Ball>();
}

Cannon::~Cannon()
{
}

void Cannon::Update()
{
	InputMove();
	InputBarrelRotation();
	Fire();
	// �ѽ� ����

	_body->Update();
	_barrel->Update();
	_ball->Update();
}

void Cannon::Render(HDC hdc)
{
	_barrel->Render(hdc);
	_body->Render(hdc);
	_ball->Render(hdc);
}

void Cannon::Fire()
{
	if (GetAsyncKeyState(VK_SPACE) & 0x8001)
	{
		if (_ball->IsFired() == false)
		{
			_ball->IsFired() = true;
			_ball->SetPosition(_body->Center() + _barrel->GetDirection() * _barrel->GetLength());
			_ball->SetDirection(_barrel->GetDirection());
			_ball->SetSpeed(3);
		}
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
	// TODO : ����Ű ���� ������ �ѽ��� ������ +�� �ǰ�
	// ����Ű �Ʒ��� ������ �ѽ��� ������ -�� �ǰ��ϱ�.

	_barrel->SetDirection((mousePos - _body->Center()).NormalVector());
}


