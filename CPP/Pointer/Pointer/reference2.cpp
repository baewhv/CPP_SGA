#include<iostream>

using namespace std;

//Call by Value
//- Read Only
//- �Ű������� ũ�� : �Ű����� �ڷ����� ������.
//Call by Address
// - ���� ���� O, �б� O
// - �Ű������� ũ�� : �ּҰ��� ũ��(x32 : 4byte / x64 : 8byte)
//Call by Reference
// - ���� ���� O, �б� O
// - �Ű������� ũ�� : �����Ϳ� ����


//�������� Ư¡
//������ - nullptr�� ����ų �� �ִ�.
//����

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
	//-> : ���� ��� ������
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




	//����1.
	//�÷��̾� 2���� ����
	//���� ���� �� ���� �ο��� �ݺ��ؼ� �̱��÷��̾� ���.
	//

	return 0;
}