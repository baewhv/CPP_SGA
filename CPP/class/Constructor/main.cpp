#include <iostream>

using namespace std;
//������.
// - ��� ������ �ʱ�ȭ�ϴ� ����.
//�Ҹ���
// - ��ü�� �����Ǹ鼭



// ��ü, �ν��Ͻ�(���� Ŭ������ �ƴϾ ��.)
// �޸𸮿� Ŭ������ ������ �����ڸ� ���� �Ҵ��ϰ�. �̴� ��ɰ� �Ӽ��� ������ �ִ�.

// ��üȭ, �ν��Ͻ�ȭ.
// Ŭ������ ������ ���� �Ҵ�.

//��� ���迡���� ������.

class Player
{
public:
	//�⺻ ������.
	//-�Ϲ������� �������� �ʾƵ� �����Ϸ��� �ڵ����� ������ش�.
	//-�ٸ� �����ڰ� ���ǵǾ��ִٸ� �⺻�����ڴ� ��������� �ʴ´�.
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
protected:
	string _name;
	int _hp;
	int _atk;
	const int _maxHp;
};


class Knight : public Player
{
public:
	Knight()
		: _stamina(0)
	{
		cout << "Knight�� �⺻������ ȣ��" << endl;
	}

	Knight(string name, int hp, int atk, int stamina)
	: Player(name, hp, atk), _stamina(stamina)//�θ� ���� �ʱ�ȭ ���2 : ���� �ʱ�ȭ �������� ����. ��� ���� ���� ����.
	{
		_name = name; 
		//�θ��� �ʱ�ȭ ���1 : ���� �ʱ�ȭ �������� ����. ��� ������ �����.

	}
	~Knight()
	{
		cout << "Knight�� �Ҹ��� ȣ��" << endl;
	}

private:
	int _stamina;
};


int main()
{
	/*
	Player p("a", 1, 2);
	Player p2 = { "b", 2, 3 };
	Player* p3 = new Player("c", 4, 56);

	p.PrintInfo();
	*/

	Knight knight = Knight("ha", 100, 10, 10);
	knight.PrintInfo();
	//Player()
	//Knight()
	//~Knight()
	//~Player()

	return 0;
}