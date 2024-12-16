#pragma once
#include "Barrel.h"

class Cannon : public enable_shared_from_this<Cannon>
{
public:
	Cannon();
	Cannon(Vector pos, int id);
	~Cannon();

	void PostInitialize() { Ready(); }
	void Update();
	void Render(HDC hdc);

	//float& Angle(float& angle) { return _angle; }
	const Vector& GetCenter() { return _body->Center(); }
	//shared_ptr<CircleCollider>& GetBody() { return _body; }

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
	float GetBarrelRatio() { return _addForce / _maxForce; }
	shared_ptr<CircleCollider> GetCollision() { return _body; }
	vector<weak_ptr<Cannon>> GetEnemies() { return _enemies; }
	void SetEnemies(vector<shared_ptr<Cannon>> cannons) 
	{
		for (auto c : cannons)
		{
			if(_id != c->_id)
			_enemies.push_back(c);
		}
	}

	
	//void SetFireEvent(function<void(void)> event) { _fireEvent = event; }

private:
	// �Է����� �¿�� �����̰� ����� �Լ�
	void InputMove();
	// �Է����� �ѽ��� ������ +,-�� �ǰ� ����� �Լ�
	void InputBarrelRotation();
	void InputFire();
	void Ready();

	//function<void(void)> _fireEvent; //���� �Լ� OK, ����Լ� OK, �Լ���ü OK => ��� callable ��ü�� ���� �� �ִ� �Լ� ������
	//using FUNC = void(*)(void); //�Ű����� void, ��ȯ�ڷ��� void�� ������ �� �ִ� �Լ� ������.
	//using FUNC_SCENE = void(Scene::*)(void); //Scene�� ����Լ� �Ű�����(void), ��ȯ�ڷ��� void,

private:
	shared_ptr<CircleCollider> _body;
	shared_ptr<class Barrel> _barrel;
	vector<shared_ptr<class Ball>> _balls;
	vector<weak_ptr<Cannon>> _enemies;

	int _poolCount = 1;
	float _angle = 0.0f;
	float _fireDelay = 1.0f;
	float _fireTimer = 0.0f;
	bool _myTurn = false;

	int _shootCount = 0;
	int _life = 0;
	int _maxLife = 2;

	bool _startCharge = false;
	float _maxForce = 10.0f;
	float _addForce = 0.0f;
	int _id;
};