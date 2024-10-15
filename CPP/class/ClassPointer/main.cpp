#include <iostream>

using namespace std;


//�Լ� �������̵�
// - �θ��� �Լ��� �ڽĿ��� ������.

// - �� ĳ���� �� ����. -> �ڽ��� �Լ��� ��� ȣ���� ���ΰ�?
// 1. ���� ����ȯ.
// 2. ���� �Լ�. (virtual function)
// ���� �Լ� ���̺� (vftable) pointer : Ŭ������ �����Լ��� �ϳ� �̻� ���ԵǸ� �ڵ����� �޸� ù ��° �ּҿ� �Ҵ�Ǵ� ������.
// => �̸� �̿��ؼ� ��ĳ���õ� ��Ȳ������ �ڽ��� �Լ��� ȣ���� �� �ִ�.

class Player
{
public:
	virtual void Attack() { cout << "Player Attack" << endl; }
	//�����Լ�

	int _hp;
};

class Knight : public Player
{
public:
	//���� �Լ� �������̵� : �θ��� �Լ��� ������
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
	((Knight*)k)->Attack();	//������ ����ȯ�� �����.
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
	}///�迭�� ��� ����.
	delete k;
	delete p;

	return 0;
}