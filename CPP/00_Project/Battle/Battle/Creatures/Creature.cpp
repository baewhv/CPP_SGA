#include "Framework.h"

void Creature::PrintCreature()
{
	cout << "-------------" << endl;
	cout << "name : " << _name << endl;
	cout << "hp   : " << _hp << " / " << _maxHp << endl;
	cout << "atk  : " << _atk << endl;
	cout << "spd  : " << _spd << endl;
	cout << "-------------" << endl;
}

void Creature::Attack(Creature* target, function<void(int)> func)
{
	if (target != nullptr && target->isAlive())
	{
		cout << endl << _name << "'s attack! " << endl;
		if (func == nullptr)
		{
			target->GetDamage(_atk);
		}
		else
		{
			target->_func = func;
			target->_func(_atk);
		}
	}
}


void Creature::GetDamage(int damage)
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
	cout << _name << "'s hp : " << _hp << " / " << _maxHp << endl;
}
