#include "../framework.h"
#include "Mage.h"

Mage::Mage(string name, int hp, int atk, int speed)
	:Player(name, hp, atk, speed)
{
}

void Mage::Attack(Creature* target)
{
	if (rand() % 10 > 5)
	{
		cout << endl << this->GetName() << "'s IceBolt Attack!" << endl;
		target->hasDamaged(_atk);
		target->AddCoolTime(-10);
	}
	else
	{
		cout << endl << this->GetName() << "'s attack! " << endl;
		target->hasDamaged(this->GetAtk());
	}
}
