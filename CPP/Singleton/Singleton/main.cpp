#include <iostream>

using namespace std;


//������ ����

//singleton

//1. �������� ���ٰ���
//2. �Ѱ��� ����.
//3. �츮�� ���� �� ������ �� �־����.

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

//static ������ �������� �ʱ�ȭ.
SoundManager* SoundManager::_instance = nullptr;

//SoundManager* sn = new SoundManager();

int main()
{
	SoundManager::CreateInstance();
	SoundManager::GetInstance()->PrintHello();
	SoundManager::DeleteInstance();
	//PrintHello();
	
	//SoundManager* sn2 = new SoundManager(); -> �߰� ������ �� �� �ִ�.
	//SoundManager* sn2 = new SoundManager(); -> ����� �������� �ܺο��� ������ �� ����.
	//SoundManager* sn2 = new SoundManager(); -> ���� ����� ȣ���ϴ� ������ ����Ϸ������� ��ü�� �־�� ����� �� �ִ�.
	//

	//delete sn;

	return 0;
}