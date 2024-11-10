#pragma once
class InputManager
{
private:
	InputManager() {}
	InputManager(const InputManager& other) {}
	InputManager& operator=(const InputManager& other) {}

	static InputManager* _inst;
public:
	static InputManager* GetInstance();
	int IntInput(int min, int max);


};

