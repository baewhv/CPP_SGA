#include "Framework.h"
#include "Boss.h"

void Boss::GetDamage(int damage, shared_ptr<Creature> c)
{

	Creature::GetDamage(damage, c);
	auto it = aggro.begin();
	for (it; it != aggro.end(); it++)
	{
		if (!it->_ptr.expired())
		{
			//비교 시 실제 내용물이 같은지 확인할 것.
			if (it->_ptr.lock().get() == c.get())
			{
				it->_totalDamage += damage;
				break;
			}
		}
	}
	if (it == aggro.end())
	{
		aggro.push_back(Aggro(c,damage));
	}
}

void Boss::Attack()
{
	if (!isAlive())
		return;

	sort(aggro.begin(), aggro.end(), [](Aggro a, Aggro b)->bool {return a._totalDamage > b._totalDamage; });
	int targetCount = 0;
	for (auto it = aggro.begin(); it != aggro.end(); it++)
	{
		if (!it->_ptr.expired())
		{
			Attack(it->_ptr.lock());
			targetCount++;
		}
		if (targetCount >= 4)
			break;
	}

}
