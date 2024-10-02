#include <iostream>

using namespace std;
//생성자.
// - 멤버 변수를 초기화하는 역할.
//소멸자
// - 객체가 삭제되면서


//상속 관계에서의 생성자.


class Player
{
public:
	//기본 생성자.
	Player()
		//빠른 초기화 영역
		:_name(""), _hp(0), _atk(0), _maxHp(0)
		//상수는 이곳에서만 초기화 가능.
	{
		cout << "기본생성자 호출" << endl;

		//늦은 초기화 영역
		this->_name = "";
		this->_hp = 0;
		this->_atk = 0;
	}
	//타입변환 생성자, 매개변수가 있는 생성자
	Player(string name, int hp, int atk)
		: _name(name), _hp(hp), _atk(atk), _maxHp(hp)
	{
		cout << "타입 변환 생성자 호출" << endl;
	}


	~Player()
	{
		cout << "소멸자 호출" << endl;
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