#include "Framework.h"
#include "GameManager.h"

GameManager* GameManager::_inst = nullptr;

Creature* GameManager::GetPlayer()
{
	if (_p == nullptr)
	{
		CreatePlayer();
	}

	return _p;
}


void GameManager::CreatePlayer()
{
	if (_p == nullptr)
	{
		cout << "You don't have any character." << endl;
	}
	else
	{
		delete _p;
	}
	cout << "Choose your job" << endl;
	cout << "[1]Knight [2]Archer [3]Mage" << endl;

	switch (InputManager::GetInstance()->IntInput(1, 3))
	{
	case 1:
		cout << "You choose Knight." << endl;
		_p = new Knight();
		break;
	case 2:
		cout << "궁수를 생성했다." << endl;
		//_p = new Archer();
		break;
	case 3:
		cout << "마법사를 생성했다." << endl;
		//_p = new Mage();
		break;
	}

	cout << "what is your name?" << endl;

	_p->SetName(InputManager::GetInstance()->StringInput(1, 10));
	InputManager::GetInstance()->ClearScrean();
}

void GameManager::SelectLocation()
{
	cout << "Where shoud I go?" << endl;
	cout << "[1]Town [2]Forest [3]Cave" << endl;
	switch (InputManager::GetInstance()->IntInput(1, 3))
	{
	case 1:
		_w = new Town();
		break;
	case 2:
		_w = new Forest();
		break;
	case 3:
		_w = new Cave();
		break;
	}
}

void GameManager::LoadScene()
{
	if (_w == nullptr)
	{
		_w = new Lobby();
	}
	_w->PlayScene();
}
