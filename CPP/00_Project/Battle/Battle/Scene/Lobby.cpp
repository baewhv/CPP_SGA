#include "Framework.h"
#include "Lobby.h"

void Lobby::PlayScene()
{
	while (GameManager::GetInstance()->GetPlayer()->isAlive())
	{
		InputManager::GetInstance()->ClearScrean();
		GameManager::GetInstance()->GetPlayer()->PrintCreature();
		GameManager::GetInstance()->SelectLocation();
		GameManager::GetInstance()->LoadScene();
	}
	cout << "You Die. GameOver." << endl;
}
