#include "Framework.h"

using namespace std;


int GetJob()
{
	int num = 0;
	while (1)
	{
		cout << "Choose your character." << endl;
		cout << "1. Knight(Link), 2. Archer(Sief), 3. Mage(Zelda)" << endl;
		cin >> num;
		if (num<=0 || num>3)
		{
			cout << "out of range." << endl;
		}
	}
	return num;
}

int main()
{
	Creature* p;
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
		break;
	}
	p->Print();
	for (int i = 0; i < 10; i++)
	{
		goblin[i]->Print();
	}
	while (knight->GetHp() > 0 && goblin->GetHp() > 0)
	{

		if (knight->CheckAtk())
		{
			if (knight->Attack(goblin))
				break;
		}
		else if (goblin->CheckAtk())
		{
			if (goblin->Attack(knight))
				break;

		}

		if (goblin->CheckAtk())
		{
			if (goblin->Attack(knight))
				break;;
		}
		else if (knight->CheckAtk())
		{
			if (knight->Attack(goblin))
				break;
		}
	}

	return 0;
}