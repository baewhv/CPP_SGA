#include <iostream>

using namespace std;

// Casting (����ȯ)
// ������ ����ȯ
// 
// �Ҿ����� ����ȯ

int aInt = 1;
short aShort = 123;
float aFloat = 1.5f;


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

int main(char args[])
{

	aInt = 32768;
	aShort = aInt;



	Player p{ 1 };
	Knight k;
	k._hp = 1;
	k._stamina = 2;

	//k = p; //
	p = k;

	
	Player* p2 = new Knight(); //UpCasting 
	Knight* k2 = (Knight*)(new Player()); //�ٿ� ĳ����. -> �Ҿ��� ĳ����
	//

	cout << k2->_hp << endl;
	cout << k2->_stamina << endl;


}