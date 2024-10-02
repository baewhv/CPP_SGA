#include<iostream>

using namespace std;


// ������
// - �����ε�(overloading) : �Լ����� �Ű������� ������ �ڷ����� �ٸ� �Լ��� �����ϴ� ��.
// - �������̵�(overriding) : �θ��� �Լ��� ���� ������. �� �Լ� �ñ״��Ŀ� �Լ� �̸��� �����ؾ��Ѵ�.


class Monster
{
public:
	void Attack() { cout << "Monster Attack!!" << endl; }
};

class Player : public Monster
{
public:
	Player operator+(const Player& other) //������ �����ε�
	{
		// this : �� ����Լ��� ȣ���� ��ü�� ������.
		this->_hp += other._hp;

		return *this;
	}

	//�Լ� �������̵�.
	void Attack() { cout << "Player Attack!" << _hp << endl; }

	int _hp;
};


int main()
{
	Player p1, p2;
	p1._hp = 1;
	p2._hp = 2;

	Player p3 = p1 + p2;

	p3.Monster::Attack();

	return 0;
}