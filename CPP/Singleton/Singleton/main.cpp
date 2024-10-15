#include <iostream>

using namespace std;


//디자인 패턴

//singleton

//1. 전역에서 접근가능
//2. 한개만 생성.
//3. 우리가 원할 때 생성할 수 있어야함.

class SoundManager
{
private:
	SoundManager() {}
	~SoundManager() {}
public:
	static void CreateInstance()
	{
		if (_instance == nullptr)
		{
			_instance = new SoundManager();
		}
	}
	static void DeleteInstance()
	{
		if (_instance != nullptr)
		{
			delete _instance;
		}
	}

	static SoundManager* GetInstance()
	{
		if (_instance != nullptr)
		{
			return _instance;
		}
		return nullptr;
	}

	void PrintHello() { cout << "HelloWorld" << endl; }

private:
	static SoundManager* _instance;
};

//static 변수는 전역에서 초기화.
SoundManager* SoundManager::_instance = nullptr;

//SoundManager* sn = new SoundManager();

int main()
{
	SoundManager::CreateInstance();
	SoundManager::GetInstance()->PrintHello();
	SoundManager::DeleteInstance();
	//PrintHello();
	
	//SoundManager* sn2 = new SoundManager(); -> 추가 생성을 할 수 있다.
	//SoundManager* sn2 = new SoundManager(); -> 멤버를 가렸으나 외부에서 생성할 수 없다.
	//SoundManager* sn2 = new SoundManager(); -> 가린 멤버를 호출하는 변수를 사용하려하지만 객체가 있어야 사용할 수 있다.
	//

	//delete sn;

	return 0;
}