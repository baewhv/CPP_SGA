#include <iostream>

using namespace std;


class Player
{
public:
	int _hp;
};

class Knight : public Player
{
public:
	int _stamina;
};


class Pet
{

};

int main()
{
	//static_cast
	//논리적으로 수행 가능한 형변환이면 OK

	int aInt = 1;
	float aFloat = static_cast<int>(aInt);
	aInt = static_cast<float>(aFloat);
	Player* p = static_cast<Player*>(new Knight());
	//p = static_cast<Player*>(new Pet());		//논리적으로 불가.
	//p = (Player*)(new Pet());					//강제적 형변환.
}