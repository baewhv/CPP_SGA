#include "../framework.h"
#include "Creature.h"

Creature::Creature()
{
	_name = "";
	_maxHp = 100;
	_hp = 100;
	_atk = 1;
	_spd = 1;
	_coolTime = 0;
}

void Creature::Attack(Creature* target)
{
	cout << endl << _name << "'s attack! " << endl;
	target->hasDamaged(_atk);
	if (target->GetHp() <= 0)
	{
		cout << target->GetName() << " is defeated. " << _name << "'s win." << endl;
	}
}

Creature::Creature(string name, int hp, int atk, int spd)
	:_name(name),_maxHp(hp), _hp(hp), _atk(atk), _spd(spd), _coolTime(0)
{
}

void Creature::Print()
{
	cout << this->_name << "'s status" << endl;
	cout << this->_name << "'s hp : " << this->_hp << endl;
	cout << this->_name << "'s atk : " << this->_atk << endl;
	cout << this->_name << "'s spd : " << this->_spd << endl << endl;
}

bool Creature::CheckAtk()
{
	if (this->GetHp() > 0 && this->GetCoolTime() >= 10)
	{
		AddCoolTime(-10);
		return true;
	}
	else
	{
		AddCoolTime(_spd);
		return false;
	}
}

void Creature::hasDamaged(int damage)
{
	cout << _name << " has " << damage << " damaged." << endl;
	if (_hp - damage > 0)
	{
		_hp -= damage;
	}
	else
	{
		_hp = 0;
	}
	cout << _name << "'s hp : " << _hp<< " / " << _maxHp << endl;
}


