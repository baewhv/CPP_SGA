#include "framework.h"

using namespace std;


void CheckAtk(Player* p)
{
	if (p->GetHp() > 0 && p->GetCoolTime() >= 10)
	{
		cout << p->GetName() << "'s attack! " << p->GetTarget()->GetName() << " has " << p->GetAtk() << " damaged." << endl;
		p->GetTarget()->hasDamaged(p->GetAtk());
		if (p->GetTarget()->GetHp() > 0)
		{
			cout << p->GetTarget()->GetName() << "'s hp : " << p->GetTarget()->GetHp() << endl;
			p->AddCoolTime(-10);
		}
		else
		{
			cout << p->GetTarget()->GetName() << "is defeated. " << p->GetName() << "'s win." << endl;
		}
		cout << endl;
	}
	else
	{
		p->AddCoolTime(p->GetSpd());
	}

}

int main()
{
	Player* char1 = new Player("Breaker", 60, 12, 4);
	Player* char2 = new Player("SoulEater", 50, 10, 8);
	char1->SetTarget(char2);
	char2->SetTarget(char1);
	char1->PrintPlayer();
	char2->PrintPlayer();

	while (char1->GetHp() > 0 && char2->GetHp() > 0)
	{
		if (char1->GetSpd() >= char2->GetSpd())
		{
			CheckAtk(char1);
			CheckAtk(char2);
		}
		else
		{
			CheckAtk(char2);
			CheckAtk(char1);
		}
	}

	return 0;
}