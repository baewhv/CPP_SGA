#include "Framework.h"
#include "Boss.h"

void Boss::Attack()
{
	if (!isAlive())
		return;

	vector<pair<Creature*, int>> aggroV(aggro.begin(),aggro.end());

	sort(aggroV.begin(), aggroV.end(), [](pair<Creature*, int> a, pair<Creature*, int> b)->bool {return a.second > b.second; });
	int targetCount = 0;
	for (auto it = aggroV.begin(); it != aggroV.end(); it++)
	{
		if (!((*it).first)->isAlive())
		{
			it = aggroV.erase(it);
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
