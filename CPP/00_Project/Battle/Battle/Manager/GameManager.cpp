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

void GameManager::SetPlayer(Creature* p)
{
	 _p = p; 
}

void GameManager::CreatePlayer()
{
	cout << "Choose your job" << endl;
	cout << "[1]Knight [2]Archer [3]Mage" << endl;

	switch (InputManager::GetInstance()->IntInput(1, 3))
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	}

}

void GameManager::LoadScene(MapList m)
{
	delete _w;
	switch (m)
	{
	case MapList::LOBBY:
		_w = new Lobby();
		break;
	case MapList::TOWN:
		break;
	case MapList::FOREST:
		break;
	case MapList::CAVE:
		break;
	default:
		break;
	}
}
