#include "framework.h"

using namespace std;

int main()
{
	Knight* knight = new Knight("Link", 70, 12, 4);
	Goblin* goblin = new Goblin(40, 8, 6);
	knight->SetTarget(goblin);
	goblin->SetTarget(knight);
	knight->Print();
	goblin->Print();

	while (knight->GetHp() > 0 && goblin->GetHp() > 0)
	{
		if (knight->GetSpd() >= goblin->GetSpd())
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
		}
		else
		{

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
	}

	return 0;
}