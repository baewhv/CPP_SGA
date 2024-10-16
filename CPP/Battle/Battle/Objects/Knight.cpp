#include "Framework.h"
#include "Knight.h"

Knight::Knight(string name, int hp, int atk)
	:Player(name, hp, atk)
{
}


void Knight::Attack(Creature* other)
{
	//creature->TakeDamage(_atk);
	//cout << _name << "이 " << creature->GetName() << "을 공격했습니다." << endl;


	float ratio = (_hp / (float)_maxHp);

	if (ratio < 0.5f)
	{
		other->TakeDamage(_atk * 2);
		cout << _name << "이 " << other->GetName() << "를 공격" << endl;
		return;
	}

	other->TakeDamage(_atk);
	cout << _name << "이 " << other->GetName() << "를 공격" << endl;
}
