#include "Framework.h"
#include "Cave.h"
#include <algorithm>

void Cave::PlayScene()
{
	CLS;
	cout << "You Came to the cave entrance." << endl;
	cout << "Do you want to enter the cave?" << endl;
	cout << "[1]Go Inside [2]Back" << endl;
	if (InputManager::GetInstance()->IntInput(1, 2) == 2)
		return;
	else
		while (1)
		{
			AttackBoss();

			if (!CheckResult())
				break;
		}
}

void Cave::AttackBoss()
{
	Players.push_back(GETPLAYER);
	_boss = new Boss();
	for (int i = 0; i < 9; i++)
	{
		Players.push_back(new Knight(i+1));
	}

	while (true)
	{
		for (auto it : Players)
		{
			Boss::GetDamaged dmg;
			dmg._target = it;
			dmg._boss = _boss;
			it->Attack(_boss, dmg);
		}
		
		_boss->Attack();
				
		if (Players.size() == 0 || !_boss->isAlive())
		{
			break;
		}
	}
}

bool Cave::CheckResult()
{
	if (!GETPLAYER->isAlive())
		return false;
	cout << "You won!" << endl;
	cout << "What do you do?" << endl;
	cout << "[1]Find other Boss [2]Back" << endl;
	if (InputManager::GetInstance()->IntInput(1, 2) == 2)
		return false;
	else
		return true;
}