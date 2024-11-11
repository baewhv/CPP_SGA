#include "Framework.h"
#include "Town.h"

void Town::PlayScene()
{
	cout << "What to do in town?" << endl;
	InputManager::GetInstance()->IntInput(0, 3);
}
