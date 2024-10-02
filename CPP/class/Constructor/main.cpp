#include <iostream>

using namespace std;
//������.
// - ��� ������ �ʱ�ȭ�ϴ� ����.
//�Ҹ���
// - ��ü�� �����Ǹ鼭


//��� ���迡���� ������.


class Player
{
public:
	//�⺻ ������.
	Player()
		//���� �ʱ�ȭ ����
		:_name(""), _hp(0), _atk(0), _maxHp(0)
		//����� �̰������� �ʱ�ȭ ����.
	{
		cout << "�⺻������ ȣ��" << endl;

		//���� �ʱ�ȭ ����
		this->_name = "";
		this->_hp = 0;
		this->_atk = 0;
	}
	//Ÿ�Ժ�ȯ ������, �Ű������� �ִ� ������
	Player(string name, int hp, int atk)
		: _name(name), _hp(hp), _atk(atk), _maxHp(hp)
	{
		cout << "Ÿ�� ��ȯ ������ ȣ��" << endl;
	}


	~Player()
	{
		cout << "�Ҹ��� ȣ��" << endl;
	}

	void PrintInfo()
	{
		cout << "Name : " << _name << endl;
		cout << "Hp : " << _hp << endl;
		cout << "Atk : " << _atk << endl;

	}

private:
	string _name;
	int _hp;
	int _atk;
	const int _maxHp;
};


int main()
{
	Player p("a", 1, 2);
	Player p2 = { "b", 2, 3 };
	Player* p3 = new Player("c", 4, 56);

	p.PrintInfo();


	return 0;
}