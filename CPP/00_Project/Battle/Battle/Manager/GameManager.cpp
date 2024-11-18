#include "Framework.h"
#include "GameManager.h"

GameManager* GameManager::_inst = nullptr;

shared_ptr<Creature>& GameManager::GetPlayer()
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
	cout << "Choose your job" << endl;
	cout << "[1]Knight [2]Archer [3]Mage" << endl;

	switch (InputManager::GetInstance()->IntInput(1, 3))
	{
	case 1:
		cout << "You choose Knight." << endl;
		_p = make_shared<Knight>();
		break;
	case 2:
		cout << "궁수를 생성했다." << endl;
		_p = make_shared<Archer>();
		break;
	case 3:
		cout << "마법사를 생성했다." << endl;
		_p = make_shared<Mage>();
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
		_w = make_shared<Town>();
		break;
	case 2:
		_w = make_shared<Forest>();
		break;
	case 3:
		_w = make_shared<Cave>();
		break;
	}
}

void GameManager::LoadScene()
{
	if (_w == nullptr)
	{
		_w = make_shared<Lobby>();
	}
	_w->PlayScene();
}
