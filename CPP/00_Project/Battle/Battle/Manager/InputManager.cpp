#include "Framework.h"
#include "InputManager.h"

InputManager* InputManager::_inst = nullptr;


InputManager* InputManager::GetInstance()
{
	if (_inst == nullptr) 
		_inst = new InputManager();
	return _inst;
}

int InputManager::IntInput(int min, int max)
{
	int input;
	while (1)
	{
		cin >> input;
		if (input < min || input > max)
		{
			cout << "Out of range." << endl;
			continue;
		}
		break;
	}
	return input;
}

string InputManager::StringInput(int min, int max)
{
	string input;
	while (1)
	{
		cin >> input;
		if (input.size() < min || input.size() > max)
		{
			cout << "Out of range." << endl;
			continue;
		}
		break;
	}
	return input;
}

void InputManager::ClearScrean()
{
	system("cls");
}


