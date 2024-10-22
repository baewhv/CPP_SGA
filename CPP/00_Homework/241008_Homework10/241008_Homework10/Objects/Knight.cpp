#include "../framework.h"
#include "Knight.h"

Knight::Knight(string name, int hp, int atk, int speed)
	:Player(name, hp, atk, speed)
{
}

void Knight::Attack(Creature* target)
{
	if (_maxHp / 2 > _hp)
	{
		cout << endl << _name << " was low HP. " << endl;
		cout << _name << "'s final attack! " << endl;
		target->hasDamaged(_atk * 2);
	}
	else
	{
		cout << endl << _name << "'s attack! " << endl;
		target->hasDamaged(_atk);
	}
}