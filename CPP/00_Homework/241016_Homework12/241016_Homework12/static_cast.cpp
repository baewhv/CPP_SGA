#include <iostream>

using namespace std;

/*
Casting 4총사 조사해오기, 예제
콜백함수에 대해서 조사해오기
-- 콜백함수의 개념
*/

//static_cast
//정적 캐스트
//형변환을 런타임이 아닌 컴파일 중 변환.

class Player
{
public:
	Player() { i = 1; }
	int i;
};

class Knight
	:public Player
{
public:
	Knight() { i = 2; c = 'a'; }
	char c;
};

class Goblin
{
public:
	Goblin() { f = 0.1f; }
	float f;
};

int main()
{
	Player* p = new Player();
	Knight* k = new Knight();
	k = static_cast<Knight*>(p);
	p = static_cast<Player*>(k);

	Goblin* g = new Goblin();
	//g = static_cast<Goblin*>(p);

	int a = 10;
	float f = 4.5f;
	char c = 'a';

	a = static_cast<int>(f); //float to int
	cout << a << endl;
	
	a = static_cast<int>(c); //char to int
	cout << a << endl;


	return 0;
}