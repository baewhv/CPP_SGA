#include "../framework.h"
#include "Knight.h"

Knight::Knight(string name, int hp, int atk, int speed)
	:Player(name, hp, atk, speed)
{
}

bool Knight::Attack(Creature* target)
{
	if (this->GetMaxHp() / 2 > this->GetHp())
	{
		cout << endl << this->GetName() << " was low HP. " << endl;
		cout << this->GetName() << "'s final attack! " << endl;
		target->hasDamaged(this->GetAtk() * 2);
	}
	else
	{
		cout << endl << this->GetName() << "'s attack! " << endl;
		target->hasDamaged(this->GetAtk());
	}
	this->AddCoolTime(-10);
	if (target->GetHp() <= 0)
	{
		cout << target->GetName() << "is defeated. " << this->GetName() << "'s win." << endl;
		return true;
	}
	return false;
}