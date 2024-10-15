#include <iostream>

using namespace std;

//인터페이스란
//UI : User Interface;
//내부 데이터를 접근할 수 있는 수단(읽기, 쓰기)

//추상화
//1. 객체화 될 수 없다.
//2. 순수가상함수가 하나 이상 포함되면 추상 클래스다.
//3. 추상클래스의 자식을 객체화 시키려면 순수가상함수를 정의해야 한다.

class Bank
{
public:
	virtual void PrintInfo() abstract; //순수가상함수

	/*virtual void PrintInfo()
	{
		cout << _money << endl;
		cout << "은행입니다." << endl;
	}*/
	void AddMoney(int value)
	{
		_money += value;
	}

protected:
	int _money;
};

class Kakao : public Bank
{
	virtual void PrintInfo() override //순수 가상 함수 오버라이딩
		//인터페이스 구현
		//C++기준 : protected 멤버변수에 접근할 수 있는 수단을 제공하라.
	{
		cout << "카카오뱅크 입니다." << endl;
		cout << "예금하신 금액은 : " << _money << endl;

	}
};

class Shinhan : public Bank
{

};


class Player
{

};

int main()
{
	//Bank* b = new Bank();	//순수 가상 함수가 있어 생성이 불가.
	Bank* k = new Kakao();

	k->AddMoney(100);
	k->PrintInfo();

	return 0;
}