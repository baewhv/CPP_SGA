#include <iostream>

using namespace std;


//함수 오버라이딩
// - 부모의 함수를 자식에서 재정의.

// - 업 캐스팅 시 문제. -> 자식의 함수를 어떻게 호출할 것인가?
// 1. 강제 형변환.
// 2. 가상 함수. (virtual function)
// 가상 함수 테이블 (vftable) pointer : 클래스에 가상함수가 하나 이상 포함되면 자동으로 메모리 첫 번째 주소에 할당되는 포인터.
// => 이를 이용해서 업캐스팅된 상황에서도 자식의 함수를 호출할 수 있다.

class Player
{
public:
	virtual void Attack() { cout << "Player Attack" << endl; }
	//가상함수

	int _hp;
};

class Knight : public Player
{
public:
	//가상 함수 오버라이딩 : 부모의 함수를 재정의
	virtual void Attack() override { cout << "Knight Attack" << endl; }
	//virtual function table;

	int _stamina;
};

class Archer : public Player
{
public:
	virtual void Attack() override { cout << "Archer Attack" << endl; }

	int _dex;
};


int main()
{
	Player* p = new Player();
	//up casting
	Player* k = new Knight();

	Player* a = new Archer();

	p->Attack();
	((Knight*)k)->Attack();	//일일이 형변환은 힘들다.
	a->Attack();

	cout << "p : " << sizeof(*p) << endl;
	cout << "k : " << sizeof(*k) << endl;
	cout << "a : " << sizeof(*a) << endl;

	
	{
		Player* arr[3];
		arr[0] = new Player();
		arr[1] = new Knight();
		arr[2] = new Archer();

		for (int i = 0; i < 3; i++)
		{
			delete arr[i];
		}
	}///배열로 묶어서 관리.
	delete k;
	delete p;

	return 0;
}