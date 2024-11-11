#include "Framework.h"
#include "Boss.h"

void Boss::Attack()
{
	sort(aggro.begin(), aggro.end(), [](pair<const Creature*, int>& a, pair<const Creature*, int>& b)->bool {return a.second > b.second; });
	int targetCount = 0;
	for (auto it = aggro.begin(); it != aggro.end(); it++)
	{
		if (!it->first->isAlive())
		{
			it = aggro.erase(it);
		}
		else
		{
			Attack(it->first);
			targetCount++;
		}
		if (targetCount >= 4)
			break;
	}

}
