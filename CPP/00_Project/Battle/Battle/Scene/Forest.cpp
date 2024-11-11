#include "Framework.h"
#include "Forest.h"

void Forest::PlayScene()
{
	CLS;
	cout << "Enter the forest." << endl;
	cout << "Do you want to search the inside of the forest?" << endl;
	cout << "[1]Go Inside [2]Back" << endl;
	if (InputManager::GetInstance()->IntInput(1, 2) == 2)
		return;
	else
		SearchGoblin();
}

void Forest::SearchGoblin()
{
	while (1)
	{
		CLS;
		int count = 3 + rand() % 5;
		cout << "You Found " << count << " Goblins." << endl;
		cout << "What do you do?" << endl;
		cout << "[1]Attack [2]Find other way [3]Runaway" << endl;
		switch (InputManager::GetInstance()->IntInput(1, 3))
		{
		case 1:
			AttackGoblin(3);
			if (CheckResult())
				continue;
			else
				return;
		case 2:
			continue;
		case 3:
			return;
		}
	}

}

void Forest::AttackGoblin(int count)
{
	for (int i = 0; i < count; i++)
	{
		goblins.push_back(new Goblin(i+1));
	}

	while (true)
	{
		int num = rand() % goblins.size();
		GETPLAYER->Attack(goblins[num], nullptr);
		if (!goblins[num]->isAlive())
		{
			goblins.erase(goblins.begin()+num);
		}

		for (auto it : goblins)
		{
			it->Attack(GETPLAYER);
		}
		if (goblins.size() == 0 || !GETPLAYER->isAlive())
		{
			break;
		}
	}
}

bool Forest::CheckResult()
{
	if (!GETPLAYER->isAlive())
		return false;
	cout << "You won!" << endl;
	cout << "What do you do?" << endl;
	cout << "[1]Find other way [2]Back" << endl;
	if (InputManager::GetInstance()->IntInput(1, 2) == 2)
		return false;
	else
		return true;
}
