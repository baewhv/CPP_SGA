#include <iostream>

using namespace std;

//dynamic_cast
//런타임 중 형 변환을 시도.
//포인터 및 참조형만 변환 가능.
//가상함수를 포함해야만 변환.
//casting이 정상적으로 가능하면 주소값을 반환.
//그렇지 않다면 nullptr 반환.


class Player
{
public:
	Player() {}
	virtual ~Player() {}
};

class Knight
	:public Player
{
public:
	Knight() { b = 10; }
	~Knight() {}
	int b;
};

class Archer
	:public Player
{
public:
	Archer() { b = 20; }
	~Archer() {}
	int b;
};

class Monster
{
public:
	Monster() {}
	virtual ~Monster() {}
};

class Goblin : public Monster
{
public:
	Goblin() {}
	~Goblin() {}
};

int main()
{
	Player* p1 = new Knight(); //기사로 업캐스팅하여 선언
	Player* p2 = new Archer(); //아쳐로 업캐스팅
	Player* p3 = new Player(); //부모 그대로 선언

	//Knight* k = p; //상속은 받고 있지만 형태가 달라 대입 불가.
	Knight* k1 = static_cast<Knight*>(p1); //다운캐스팅 성공
	cout << k1->b << endl;				   //
	Knight* k2 = static_cast<Knight*>(p2); //다운캐스팅은 가능하나
	cout << k2->b << endl;				   //초기화 이후 엉뚱한 값 배정 = 불안정
	Knight* k3 = static_cast<Knight*>(p3); //다운캐스팅은 가능하나
	cout << k3->b << endl;				   //초기화 이후 엉뚱한 값 배정 = 불안정

	Knight* k4 = dynamic_cast<Knight*>(p1); //다운캐스팅 성공
	if (k4 != nullptr)
		cout << k4->b << endl;
	Knight* k5 = dynamic_cast<Knight*>(p2); //부모는 같지만 가상함수 테이블 정보가 달라 실패.
	if (k5 != nullptr)
		cout << k5->b << endl;
	Knight* k6 = dynamic_cast<Knight*>(p3); //부모를 대입하였지만 가상함수 테이블 정보가 달라 실패.
	if (k6 != nullptr)
		cout << k6->b << endl;

	//Monster* m1 = new Goblin();
	//Monster* m2 = new Monster();

	//Goblin* g3 = dynamic_cast<Goblin*>(m1); //컴파일 단계에서 클래스에 가상 함수가 있는지 체크한다.
	//if (g3 != nullptr)
	//	cout << k3->b << endl;
	//Goblin* g4 = dynamic_cast<Goblin*>(m2);
	//if (g4 != nullptr)
	//	cout << k4->b << endl;

	//Monster* m1 = new Goblin();

	//Knight* k5 = dynamic_cast<Knight*>(m1);
	//if (k5 != nullptr)
	//	cout << k5->b << endl;
	//else
	//	cout << "fail(monster to knight)" << endl;
	return 0;
}