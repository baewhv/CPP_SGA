#pragma once
#include "Barrel.h"

class Cannon : public enable_shared_from_this<Cannon>
{
public:
	Cannon();
	Cannon(Vector pos);
	~Cannon();

	void PostInitialize() { Ready(); }
	void Update();
	void Render(HDC hdc);

	float& Angle(float& angle) {return _angle; }
	const Vector& GetCenter() { return _body->Center(); }

	shared_ptr<CircleCollider>& GetBody() { return _body; }

	void Fire();
	

	bool IsFireReady() 
	{ 
		_fireTimer += 0.01f;  
		if (_fireTimer > _fireDelay)
		{
			_fireTimer = 0.0f;
			return true;
		}
		return false;
	}

private:
	// �Է����� �¿�� �����̰� ����� �Լ�
	void InputMove();
	// �Է����� �ѽ��� ������ +,-�� �ǰ� ����� �Լ�
	void InputBarrelRotation();

	void InputFire();
	void Ready() { _barrel->SetCannon(shared_from_this()); }

private:
	shared_ptr<CircleCollider> _body;
	//shared_ptr<Line> _barrel;
	shared_ptr<class Barrel> _barrel;
	vector<shared_ptr<class Ball>> _balls;
	int _poolCount = 30;
	float _angle = 0.0f;
	bool _shootStandby = false;

	float _fireDelay = 1.0f;
	float _fireTimer = 0.0f;
};