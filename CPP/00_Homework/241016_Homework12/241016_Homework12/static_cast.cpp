#include <iostream>

using namespace std;

/*
Casting 4�ѻ� �����ؿ���, ����
�ݹ��Լ��� ���ؼ� �����ؿ���
-- �ݹ��Լ��� ����
*/

//static_cast
//���� ĳ��Ʈ
//����ȯ�� ��Ÿ���� �ƴ� ������ �� ��ȯ.

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