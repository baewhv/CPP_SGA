#include <iostream>

using namespace std;

//reinterpret_cast
// 허용하지 않는 형변환을 강제적으로 시행한다.
// 포인터/참조형에 사용한다.


class Player
{
public:
	Player() { a1 = 20; }
	int a1;
};

class Goblin
{
public:
	Goblin() { b = 1; }
	int b;
};

class Kobold
{
public:
	Kobold() { f = 1.5f; }
	float f;
};

int main()
{
	Player* p = new Player();

	Goblin* g = reinterpret_cast<Goblin*>(p); //상속 관계가 아니지만 캐스팅을 허용한다.
	cout << g->b << endl; //우연히 내부 형태가 같다면 출력물에 이상이 없을 순 있다.

	Kobold* k = reinterpret_cast<Kobold*>(p);
	cout << k->f << endl; //자료형이 달라 원치않는 값이 출력됨.
	cout << *(reinterpret_cast<int*>(&(k->f))) << endl;

	return 0;
}