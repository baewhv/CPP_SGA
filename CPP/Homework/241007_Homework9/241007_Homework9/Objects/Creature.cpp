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

bool Creature::Attack(Creature* target)
{
	cout << endl << this->GetName() << "'s attack! " << endl;
	target->hasDamaged(this->_atk);
	if (target->GetHp() <= 0)
	{
		cout << target->GetName() << " is defeated. " << _name << "'s win." << endl;
		return true;
	}
	this->AddCoolTime(-10);
	return false;
	
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
		return true;
	}
	else
	{
		this->AddCoolTime(this->GetSpd());
		return false;
	}
}

void Creature::hasDamaged(int damage)
{
	cout << this->_name << " has " << damage << " damaged." << endl;
	if (this->_hp - damage > 0)
	{
		this->_hp -= damage;
	}
	else
	{
		this->_hp = 0;
	}
	cout << this->_name << "'s hp : " << this->_hp<< " / " << this->_maxHp << endl;
}


