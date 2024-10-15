#include "Framework.h"

using namespace std;

int GetJob();
void PrintMonsters(Creature* m[], int size);
void AttackMonsters(Creature* m[], int size, Creature* target);
Creature* ChooseMonster(Creature* m[], int size);
bool CheckEnd(Creature* p, Creature* m[]);
bool CheckGoblinAlive(Creature* m[]);

int main()
{
	Creature* p = nullptr;
	Creature* goblin[10];

	switch (GetJob())
	{
	case 1:
		p = new Knight("Link", 150, 16, 10);
		break;
	case 2:
		p = new Knight("Sief", 120, 12, 13);
		break;
	case 3:
		p = new Knight("Zelda", 130, 15, 11);
		break;
	default:
		p = new Knight("Not Seleted", 1000, 10, 10);
		break;
	}

	for (int i = 0; i < 10 ;i++)
	{
		goblin[i] = new Goblin("goblin" + to_string(i+1));
	}


	p->Print();
	PrintMonsters(goblin, 10);

	while (true)
	{
		if (p->CheckAtk())
			p->Attack(ChooseMonster(goblin, 10));
		AttackMonsters(goblin, 10, p);

		if (CheckEnd(p, goblin))
		{
			break;
		}
	}

	return 0;
}

int GetJob()
{
	int num = 0;
	while (1)
	{
		cout << "Choose your character." << endl;
		cout << "1. Knight(Link), 2. Archer(Sief), 3. Mage(Zelda)" << endl;
		cin >> num;
		if (num <= 3 && num > 0)
		{
			break;
		}
		cout << "out of range." << endl;
		
	}
	return num;
}

void PrintMonsters(Creature* m[], int size)
{
	for (int i = 0; i < size; i++)
	{
		m[i]->Print();
	}
}

void AttackMonsters(Creature* m[], int size, Creature* target)
{
	for (int i = 0; i < size; i++)
	{
		if (m[i]->CheckAtk() && target->isAlive())
		{
			m[i]->Attack(target);
		}
	}
}

Creature* ChooseMonster(Creature* m[], int size)
{
	int random = 0;
	while (true)
	{
		random = rand() % size;
		if(m[random]->isAlive())
			return m[random];
	}
	return nullptr;
}

bool CheckEnd(Creature* p, Creature* m[])
{
	if (!(p->isAlive()))
	{
		cout << "Goblin's win." << endl;
		return true;
	}
	if (CheckGoblinAlive(m))
	{
		cout << p->GetName() <<"'s win." << endl;
		return true;
	}

	return false;
}

bool CheckGoblinAlive(Creature* m[])
{
	for (int i = 0; i < 10; i++)
	{
		if (m[i]->isAlive())
			return false;
	}
	return true;
}