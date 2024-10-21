#include <iostream>

using namespace std;

//�Լ��� ��� ��򰡿� ����ǰ� �ִ�.

//�Լ��� �Ű������� �Ѱ� ���߿� ȣ�� / �ٸ� �������� ȣ�� / �̺�Ʈ �߻� �� ȣ��

void(*func)(void); //�Լ� ������
void(*func1)(int); //�Ű������� int�� �Լ� ������

//typedef
typedef unsigned int UINT;

typedef void(*FUNC)();

void HelloWorld()
{
	cout << "Hello World!!" << endl;
}

void PrintNum(int a)
{
	cout << a << endl;
}

void HelloClass()
{
	cout << "Hello Class" << endl;
}

class Pet
{
public:
	void Bark() { cout << "bow wow" << endl; }
};

class Player
{
public:
	typedef void(Pet::* PetFunc)(void);

	void Hello()
	{
		if (_introduce != nullptr)
			_introduce();
	}

	void SetIntro(FUNC func)
	{
		_introduce = func;
	}

	void Attack(Pet* pet)
	{
		cout << "Player Attack!!!" << endl;
		if (pet != nullptr && _petFunc != nullptr)
		{
			(pet->*_petFunc)();
		}
	}

	void Attack(PetFunc pFunc, Pet* pet)
	{
		cout << "Player Attack!!!" << endl;
		if (pet != nullptr && pFunc != nullptr)
		{
			(pet->*pFunc)();
		}
	}

	void SetPetFunc(PetFunc func)
	{
		_petFunc = func;
	}

private:
	FUNC _introduce;
	PetFunc _petFunc; //class pet�� void(void)�Լ��� ����Ű�� �Լ� ������

};


int main(void) {

	func = &HelloWorld;

	func();

	func1 = &PrintNum;

	func1(1);

	FUNC voidFunc = &HelloWorld;
	voidFunc();

	Player* p = new Player();
	Pet* pet = new Pet();
	p->SetIntro(&HelloWorld);
	p->Hello();

	p->SetIntro(&HelloClass);
	p->Hello();

	p->SetPetFunc(&Pet::Bark);
	p->Attack(pet);



	return 0;
}
