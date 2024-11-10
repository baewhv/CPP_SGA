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
			break;
		}
		cout << "Out of range." << endl;
	}
	return input;
}
