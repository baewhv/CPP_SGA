#include "../framework.h"
#include "Mage.h"

Mage::Mage(string name, int hp, int atk, int speed)
	:Player(name, hp, atk, speed)
{
}

void Mage::Attack(Creature* target)
{
	SoundManager::Instance()->PlaySound(_name, MageAttack);
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
void Mage::hasDamaged(int damage)
{
	Creature::hasDamaged(damage);
	SoundManager::Instance()->PlaySound(_name, MageDamaged);
}

bool Mage::isAlive()
{
	if (_hp > 0)
	{
		return true;
	}
	SoundManager::Instance()->PlaySound(_name, MageDie);
	return false;
}