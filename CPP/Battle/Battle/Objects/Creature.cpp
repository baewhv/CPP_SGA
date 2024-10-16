#include "../framework.h"
#include "Creature.h"

Creature::Creature(string name, int hp, int atk)
	:_name(name), _hp(hp), _atk(atk), _maxHp(hp)
{
}


void Creature::PrintInfo()
{
	cout << "name : " << _name << endl;
	cout << "HP : " << _hp << endl;
	cout << "ATK : " << _atk << endl;
}

void Creature::Attack(Creature* creature)
{
	creature->TakeDamage(_atk);
	cout << _name << "이 " << creature->GetName() << "을 공격했습니다." << endl;
}

void Creature::TakeDamage(int amount)
{
	//TODO
	//방어력 버프가 있다면
	//amount -= amount -armor


	_hp -= amount;

	if (_hp < 0)
		_hp = 0;
}

//전방 선언
//플레이어가 클래스라는것을 미리 알려줌.


