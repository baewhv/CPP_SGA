#include <iostream>

using namespace std;
//생성자.
// - 멤버 변수를 초기화하는 역할.
//소멸자
// - 객체가 삭제되면서



// 객체, 인스턴스(굳이 클래스가 아니어도 됨.)
// 메모리에 클래스로 변수를 생성자를 통해 할당하고. 이는 기능과 속성을 가지고 있다.

// 객체화, 인스턴스화.
// 클래스로 변수를 만들어서 할당.

//상속 관계에서의 생성자.

class Player
{
public:
	//기본 생성자.
	//-암묵적으로 정의하지 않아도 컴파일러가 자동으로 만들어준다.
	//-다른 생성자가 정의되어있다면 기본생성자는 만들어지지 않는다.
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
		cout << "Knight의 기본생성자 호출" << endl;
	}

	Knight(string name, int hp, int atk, int stamina)
	: Player(name, hp, atk), _stamina(stamina)//부모 영역 초기화 방법2 : 빠른 초기화 영역에서 선언. 상수 또한 세팅 가능.
	{
		_name = name; 
		//부모의 초기화 방법1 : 늦은 초기화 영역에서 선언. 상수 세팅이 어려움.

	}
	~Knight()
	{
		cout << "Knight의 소멸자 호출" << endl;
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