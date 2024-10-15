#pragma once
#include <iostream>

using namespace std;

class Player
{
public:
	Player(string name, int hp, int atk, int speed);

	void PrintPlayer()
	{
		cout << this->_name << "'s status" << endl;
		cout << this->_name << "'s hp : " << this->_hp << endl;
		cout << this->_name << "'s atk : " << this->_atk << endl;
		cout << this->_name << "'s spd : " << this->_spd << endl << endl;
	}

	bool hasDamaged(int damage)
	{
		if (this->_hp - damage > 0)
		{
			this->_hp -= damage;
			return true;
		}
		else
		{
			this->_hp = 0;
			return false;
		}
	}
	void AddCoolTime(int ct)
	{
		_coolTime += ct;
	}

	int GetHp() { return _hp; }
	int GetAtk() { return _atk; }
	int GetSpd() { return _spd; }
	int GetCoolTime() { return _coolTime; }
	string GetName() { return _name; }
	Player* GetTarget() { return _target; }
	void SetTarget(Player* target) { this->_target = target; }

private:
	int _hp;
	int _atk;
	int _spd;
	int _coolTime;
	string _name;
	Player* _target = nullptr;
};

