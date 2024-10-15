#include <iostream>

using namespace std;


//static 변수
// CODE
// DATA
// - 전역 변수
// - 정적 변수(static)
// 프로그램 시작 시 할당 / 종료시 해제
// STACK
// -지역, 매개변수, 반환주소값 => Stackframe
// HEAP
// - 사용자 메모리

// - 정적 / 동적
// 정적 : 컴파일 시간에 생성. 런타임에 해제되지 않는다.
// 동적 : 런타임에 생성되고 해제된다.

class Marine
{
public:
	// 멤버 함수의 호출 조건
	// - 어디 산하인지 알 수 있어야한다.
	// - 객체가 있어야 한다.

	void PrintInfo() 
	{
		cout << _hp << endl;
		cout << _atk << endl;
	}

	//정적 멤버함수 : static 멤버함수
	//=> 멤버함수를 전역함수처럼 만들어준다.
	//정적 멤버 함수는 정적 멤버 변수에만 접근해 사용할 수 있다.

	static void  Hello()
	{
		cout << "Hello World" << endl;
		//cout << _hp << endl; -> 어떤 객체에서 호출했는지 알 수 없다.
		//cout << _hp << endl;
		cout << _atk << endl;
	}

public:
	int _hp;

	//정적 변수.
	static int _atk;
};

//정적 변수는 전역에서 초기화해준다.
int Marine::_atk = 0;


int main()
{
	Marine::_atk = 5;
	Marine::Hello(); //정적 멤버함수의 호출.

	Marine* arr[100];
	for (int i = 0; i < 100; i++)
	{
		arr[i] = new Marine();
		arr[i]->_hp = 50;
		arr[i]->_atk = 5;
	}

	for (int i = 0; i < 100; i++)
	{
		arr[i]->PrintInfo();
	}

	for (int i = 0; i < 100; i++)
	{
		delete arr[i];
	}

	return 0;
}