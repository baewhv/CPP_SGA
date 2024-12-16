#include "framework.h"
#include "Barrel.h"
#include "Ball.h"
#include "Cannon.h"

Cannon::Cannon() : Cannon(Vector(350, 350), 0)
{
}

Cannon::Cannon(Vector pos, int id)
{
	_life = _maxLife;
	_id = id;
	_body = make_shared<CircleCollider>(pos, 50);
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

	if (_myTurn == false) return;

	if (_startCharge)
	{
		if (_addForce > _maxForce)
			_addForce = _maxForce;
		_addForce += 0.1f;
	}

	InputMove();
	InputBarrelRotation();
	InputFire();

	// �ѽ� ����
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
	auto iter = std::find_if(_balls.begin(), _balls.end(), [](const shared_ptr<Ball>& ball) -> bool {
		if (ball->IsFired() == false)
			return true;
		return false;
		});
	if (iter == _balls.end()) return;
	(*iter)->SetSpeed(5.0f + _addForce);
	(*iter)->Fire(_barrel->GetMuzzle(), _barrel->GetDirection());
	_shootCount++;
	_myTurn = false;
	_addForce = 0.0f;

	//if (_fireEvent != nullptr)
	//	_fireEvent();
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

void Cannon::InputFire()
{
	if (GetAsyncKeyState(VK_SPACE) & 0x8001)
		_startCharge = true;
	else
	{
		if (_startCharge)
		{
			Fire();
			_startCharge = false;
		}
	}
}

void Cannon::Ready()
{
	_barrel->SetCannon(shared_from_this());
	for (auto c : _balls)
	{
		c->SetCannon(shared_from_this());
	}
}


