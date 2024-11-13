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
	_boss = make_shared<Boss>();
	auto _castBoss = dynamic_pointer_cast<Boss>(_boss);
	for (int i = 0; i < 9; i++)
	{
		shared_ptr<Creature> temp;
		switch (rand()%3)
		{
		case 0:
			temp = make_shared<Knight>(i + 1);
			break;
		case 1:
			temp = make_shared<Archer>(i + 1);
			break;
		case 2:
			temp = make_shared<Mage>(i + 1);
			break;
		default:
			break;
		}
		Players.push_back(temp);
	}

	while (true)
	{
		for (auto it : Players)
		{
			it->Attack(_boss);
		}
		

		
		if (_castBoss != nullptr)
		{
			_castBoss->Attack();
		}
				
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