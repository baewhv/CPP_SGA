#include <iostream>

using namespace std;

//dynamic_cast
//��Ÿ�� �� �� ��ȯ�� �õ�.
//������ �� �������� ��ȯ ����.
//�����Լ��� �����ؾ߸� ��ȯ.
//casting�� ���������� �����ϸ� �ּҰ��� ��ȯ.
//�׷��� �ʴٸ� nullptr ��ȯ.


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
	Player* p1 = new Knight(); //���� ��ĳ�����Ͽ� ����
	Player* p2 = new Archer(); //���ķ� ��ĳ����
	Player* p3 = new Player(); //�θ� �״�� ����

	//Knight* k = p; //����� �ް� ������ ���°� �޶� ���� �Ұ�.
	Knight* k1 = static_cast<Knight*>(p1); //�ٿ�ĳ���� ����
	cout << k1->b << endl;				   //
	Knight* k2 = static_cast<Knight*>(p2); //�ٿ�ĳ������ �����ϳ�
	cout << k2->b << endl;				   //�ʱ�ȭ ���� ������ �� ���� = �Ҿ���
	Knight* k3 = static_cast<Knight*>(p3); //�ٿ�ĳ������ �����ϳ�
	cout << k3->b << endl;				   //�ʱ�ȭ ���� ������ �� ���� = �Ҿ���

	Knight* k4 = dynamic_cast<Knight*>(p1); //�ٿ�ĳ���� ����
	if (k4 != nullptr)
		cout << k4->b << endl;
	Knight* k5 = dynamic_cast<Knight*>(p2); //�θ�� ������ �����Լ� ���̺� ������ �޶� ����.
	if (k5 != nullptr)
		cout << k5->b << endl;
	Knight* k6 = dynamic_cast<Knight*>(p3); //�θ� �����Ͽ����� �����Լ� ���̺� ������ �޶� ����.
	if (k6 != nullptr)
		cout << k6->b << endl;

	//Monster* m1 = new Goblin();
	//Monster* m2 = new Monster();

	//Goblin* g3 = dynamic_cast<Goblin*>(m1); //������ �ܰ迡�� Ŭ������ ���� �Լ��� �ִ��� üũ�Ѵ�.
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