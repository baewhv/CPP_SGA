#include "Framework.h"

int main()
{
	GameManager::GetInstance()->SetPlayer(new Creature("nav",1,2,3));
	

	return 0;
}
