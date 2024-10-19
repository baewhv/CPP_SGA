#include <iostream>

using namespace std;

// Casting (형변환)
// 안전한 형변환
// 
// 불안전한 형변환

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
	Knight* k2 = (Knight*)(new Player()); //다운 캐스팅. -> 불안전 캐스팅
	//

	cout << k2->_hp << endl;
	cout << k2->_stamina << endl;


}