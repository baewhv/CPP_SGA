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
	bool GetTurn() { return _myTurn; }
	void SetTurn(bool b) { _myTurn = b; }
	int& ShootCount() { return _shootCount; }
	int GetMaxLife() { return _maxLife; }
	int& Life() { return _life; }

	bool IsAlive() { return _life > 0; }

private:
	// 입력으로 좌우로 움직이게 만드는 함수
	void InputMove();
	// 입력으로 총신의 각도가 +,-가 되게 만드는 함수
	void InputBarrelRotation();

	void InputFire();
	void Ready();
private:
	shared_ptr<CircleCollider> _body;
	//shared_ptr<Line> _barrel;
	shared_ptr<class Barrel> _barrel;
	vector<shared_ptr<class Ball>> _balls;
	int _poolCount = 30;
	float _angle = 0.0f;
	float _fireDelay = 1.0f;
	float _fireTimer = 0.0f;
	bool _myTurn = false;

	int _shootCount = 0;
	int _life;
	int _maxLife = 5;

	bool _startCharge = false;
	float _addForce = 0.0f;
};