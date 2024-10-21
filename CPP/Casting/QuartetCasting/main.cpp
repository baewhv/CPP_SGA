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
	//논리적으로 수행 가능한 형변환이면 OK

	int aInt = 1;
	float aFloat = static_cast<int>(aInt);
	aInt = static_cast<float>(aFloat);
	Player* p = static_cast<Player*>(new Knight());
	//p = static_cast<Player*>(new Pet());		//논리적으로 불가.
	//p = (Player*)(new Pet());					//강제적 형변환.

	PrintType(p);

	//dynamic_cast 39.99999%
	// - 상속 구조 및 vftable을 갖고 있어야 사용 가능하다.
	// - 런타임 중 vftable 을 비교해 성공 시 포인터 반환, 실패 시 nullptr 반환.

	//const_cast
	//rvalue => 리터럴 상수 => data영역 -> rodata

	const char* str = "bjm"; //data영역에 만들어두고 그 주소값을 가지고 있음(4byte)
	char str2[7] = "bjmbjm"; //stack영역에 생성되

	char* temp = const_cast<char*>(str);
	*temp = 'y';

	cout << *temp << endl;

	
}