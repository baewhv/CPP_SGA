#include <iostream>

using namespace std;

struct Player
{
	//멤버 변수
	int hp;
	int atk;
	string name;
};

//const (data)* const ptr =>  read Only
void PrintPlayer(Player p)
{
	cout << "NAME : " << p.name << endl;
	cout << "HP : " << p.hp << endl;
	cout << "ATK : " << p.atk << endl;
}
// Call by Value : 호출할 때 값 전달.
void SetPlayer(Player p, string name, int hp, int atk)
{
	//(변수명).(멤버) = 멤버 연산자
	p.name = name;
	p.hp = hp;
	p.atk = atk;
}

void SetPlayer(Player* p, string name, int hp, int atk)
{
	(*p).name = name;
	(*p).hp = hp;
	(*p).atk = atk;
}

//ptr + 정수 : ptr의 자료형 크기만큼 더한다.

int main()
{
	Player p;
	p.hp = 100;
	p.atk = 10;
	p.name = "bjm";
	SetPlayer(p, "bjm2", 150, 15);
	PrintPlayer(p);

	cout << sizeof(&p) << endl;

	return 0;
}