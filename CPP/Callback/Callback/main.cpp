#include <iostream>

using namespace std;

//함수도 사실 어딘가에 저장되고 있다.

//함수를 매개변수로 넘겨 나중에 호출 / 다른 누군가가 호출 / 이벤트 발생 시 호출

void(*func)(void); //함수 포인터
void(*func1)(int); //매개변수가 int인 함수 포인터

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
	PetFunc _petFunc; //class pet의 void(void)함수를 가리키는 함수 포인터

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
