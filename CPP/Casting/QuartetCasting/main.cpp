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
	//�������� ���� ������ ����ȯ�̸� OK

	int aInt = 1;
	float aFloat = static_cast<int>(aInt);
	aInt = static_cast<float>(aFloat);
	Player* p = static_cast<Player*>(new Knight());
	//p = static_cast<Player*>(new Pet());		//�������� �Ұ�.
	//p = (Player*)(new Pet());					//������ ����ȯ.
}