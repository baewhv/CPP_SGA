#include "../framework.h"
#include "Archer.h"

Archer::Archer(string name, int hp, int atk, int speed)
	:Player(name, hp, atk, speed)
{
}

void Archer::Attack(Creature* target)
{
	SoundManager::Instance()->PlaySound(_name, ArcherAttack);
	if (rand() % 10 > 1)
	{
		cout << endl << this->GetName() << "'s Critical Arrow!" << endl;
		target->hasDamaged(_atk * 3);
	}
	else
	{
		cout << endl << this->GetName() << "'s shoot an arrow! " << endl;
		target->hasDamaged(this->GetAtk());
	}
}

void Archer::hasDamaged(int damage)
{
	Creature::hasDamaged(damage);
	SoundManager::Instance()->PlaySound(_name, ArcherDamaged);
}

bool Archer::isAlive()
{
	if (_hp > 0)
	{
		return true;
	}
	SoundManager::Instance()->PlaySound(_name, ArcherDie);
	return false;
}
