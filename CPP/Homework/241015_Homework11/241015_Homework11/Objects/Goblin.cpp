#include "../framework.h"
#include "Goblin.h"

Goblin::Goblin(string name)
	:Monster(name, 20 + rand() % 10, 3 + rand() % 5, 1 + rand() % 4)
{

}

Goblin::Goblin(int hp, int atk, int speed)
	: Monster("Goblin", hp, atk, speed)
{

}

void Goblin::Attack(Creature* p)
{
	Creature::Attack(p);
}

void Goblin::hasDamaged(int damage)
{
	Creature::hasDamaged(damage);
	SoundManager::Instance()->PlaySound(_name, GoblinDamaged);
}

bool Goblin::isAlive()
{
	if (_hp > 0)
	{
		return true;
	}
	SoundManager::Instance()->PlaySound(_name, GoblinDie);
	return false;
}