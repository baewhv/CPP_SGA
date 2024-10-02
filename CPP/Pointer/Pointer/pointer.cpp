#include <iostream>

using namespace std;

struct Player
{
	//��� ����
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
// Call by Value : ȣ���� �� �� ����.
void SetPlayer(Player p, string name, int hp, int atk)
{
	//(������).(���) = ��� ������
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

//ptr + ���� : ptr�� �ڷ��� ũ�⸸ŭ ���Ѵ�.

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