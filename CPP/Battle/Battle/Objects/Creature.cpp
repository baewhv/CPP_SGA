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
	cout << _name << "�� " << creature->GetName() << "�� �����߽��ϴ�." << endl;
}

void Creature::TakeDamage(int amount)
{
	//TODO
	//���� ������ �ִٸ�
	//amount -= amount -armor


	_hp -= amount;

	if (_hp < 0)
		_hp = 0;
}

//���� ����
//�÷��̾ Ŭ������°��� �̸� �˷���.


