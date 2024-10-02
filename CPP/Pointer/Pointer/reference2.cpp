#include<iostream>

using namespace std;

//Call by Value
//- Read Only
//- 매개변수의 크기 : 매개변수 자료형을 따른다.
//Call by Address
// - 원본 수정 O, 읽기 O
// - 매개변수의 크기 : 주소값의 크기(x32 : 4byte / x64 : 8byte)
//Call by Reference
// - 원본 수정 O, 읽기 O
// - 매개변수의 크기 : 포인터와 동일


//참조형의 특징
//포인터 - nullptr을 가르킬 수 있다.
//공통

struct Player
{
	int hp;
	int atk;
	string name;
};

void PrintPlayer(const Player& ref)
{
	cout << ref.name << endl;
	cout << ref.hp << endl;
	cout << ref.atk << endl;
}

void SetPlayer(Player* ptr, string name, int hp, int atk)
{
	//-> : 간접 멤버 연산자
	(*ptr).name = name;
	ptr->hp = hp;
	ptr->atk = atk;
}


void SetPlayer(Player& ref, string name, int hp, int atk)
{
	ref.name = name;
	ref.hp = hp;
	ref.atk = atk;
}

int main()
{
	Player p;
	p.name = "";
	p.hp = 0;
	p.atk = 0;

	PrintPlayer(p);
	SetPlayer(p, "bjm", 100, 5);
	PrintPlayer(p);

	Player p2;
	SetPlayer(&p2, "bjm2", 150, 50);
	PrintPlayer(p2);




	//과제1.
	//플레이어 2명을 세팅
	//서로 죽을 때 까지 싸움을 반복해서 이긴플레이어 출력.
	//

	return 0;
}