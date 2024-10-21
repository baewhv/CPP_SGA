#include <iostream>

using namespace std;


class Player
{
public:
	Player() : _type(0) {}
	virtual ~Player() {}

	int _type;
	int _hp;
};

class Knight : public Player
{
public:
	Knight() { _type = 1; }
	virtual ~Knight() {}

	int _stamina;
};
class Archer : public Player
{
public:
	Archer() { _type = 2; }
	virtual ~Archer() {}

	int _critical;
};

class Pet
{

};

void PrintType(Player* p)
{
	int type = p->_type;

	switch (type)
	{
	case 0:
	{
		Player* p2 = dynamic_cast<Player*>(p);
		if (p2 != nullptr)
		{
			cout << "Player" << endl;
		}
	}

	case 1:
	{
		Knight* k = dynamic_cast<Knight*>(p);
		if (k != nullptr)
		{
			cout << "Knight" << endl;
		}
	}
	break;
	case 2:
	{
		Archer* a = dynamic_cast<Archer*>(p);
		if (a != nullptr)
		{
			cout << "Archer" << endl;
		}
	}
	break;
	default:
		break;
	}
}


int main()
{
	//static_cast 60%
	//�������� ���� ������ ����ȯ�̸� OK

	int aInt = 1;
	float aFloat = static_cast<int>(aInt);
	aInt = static_cast<float>(aFloat);
	Player* p = static_cast<Player*>(new Knight());
	//p = static_cast<Player*>(new Pet());		//�������� �Ұ�.
	//p = (Player*)(new Pet());					//������ ����ȯ.

	PrintType(p);

	//dynamic_cast 39.99999%
	// - ��� ���� �� vftable�� ���� �־�� ��� �����ϴ�.
	// - ��Ÿ�� �� vftable �� ���� ���� �� ������ ��ȯ, ���� �� nullptr ��ȯ.

	//const_cast
	//rvalue => ���ͷ� ��� => data���� -> rodata

	const char* str = "bjm"; //data������ �����ΰ� �� �ּҰ��� ������ ����(4byte)
	char str2[7] = "bjmbjm"; //stack������ ������

	char* temp = const_cast<char*>(str);
	*temp = 'y';

	cout << *temp << endl;

	
}