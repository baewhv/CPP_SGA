#include <iostream>

using namespace std;

//reinterpret_cast
// ������� �ʴ� ����ȯ�� ���������� �����Ѵ�.
// ������/�������� ����Ѵ�.


class Player
{
public:
	Player() { a1 = 20; }
	int a1;
};

class Goblin
{
public:
	Goblin() { b = 1; }
	int b;
};

class Kobold
{
public:
	Kobold() { f = 1.5f; }
	float f;
};

int main()
{
	Player* p = new Player();

	Goblin* g = reinterpret_cast<Goblin*>(p); //��� ���谡 �ƴ����� ĳ������ ����Ѵ�.
	cout << g->b << endl; //�쿬�� ���� ���°� ���ٸ� ��¹��� �̻��� ���� �� �ִ�.

	Kobold* k = reinterpret_cast<Kobold*>(p);
	cout << k->f << endl; //�ڷ����� �޶� ��ġ�ʴ� ���� ��µ�.
	cout << *(reinterpret_cast<int*>(&(k->f))) << endl;

	return 0;
}