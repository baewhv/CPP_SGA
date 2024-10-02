#include<iostream>

using namespace std;


// 다형성
// - 오버로딩(overloading) : 함수에서 매개변수의 개수나 자료형이 다른 함수로 정의하는 것.
// - 오버라이딩(overriding) : 부모의 함수를 새로 재정의. 단 함수 시그니쳐와 함수 이름이 동일해야한다.


class Monster
{
public:
	void Attack() { cout << "Monster Attack!!" << endl; }
};

class Player : public Monster
{
public:
	Player operator+(const Player& other) //연산자 오버로딩
	{
		// this : 이 멤버함수를 호출한 객체의 포인터.
		this->_hp += other._hp;

		return *this;
	}

	//함수 오버라이딩.
	void Attack() { cout << "Player Attack!" << _hp << endl; }

	int _hp;
};


int main()
{
	Player p1, p2;
	p1._hp = 1;
	p2._hp = 2;

	Player p3 = p1 + p2;

	p3.Monster::Attack();

	return 0;
}