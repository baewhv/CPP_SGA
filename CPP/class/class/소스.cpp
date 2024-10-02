#include <iostream>

using namespace std;
// class
// 절차지향 : 절차대로 실행
// 객체지향 : 객체가 속성과 기능을 갖는 것에 초점을 두고 프로그래밍하는 것.
// 객체 : 속성 + 기능 -> 메모리에 할당되어있는 것.

// 객체 지향의 3속성
// 은닉성(캡슐화)
//	- 접근 지정자
//  - public : 모든 곳에서 객체의 멤버에 접근, 수정 가능.
//  - private : 클래스 안에서만 멤버에 접근, 수정 가능.
//  - protected : 클래스와 자식들에게서만 접근, 수정가능.
// 상속성
// 다형성(Polymorphism) => 형태가 다양하다.


//복합자료형으로 주로 사용.
struct Player
{
public:
	int hp;
	int mp;
private:
	int h2;
	void sdfkjwe(int a) {}
	Player()
	{

	}
	~Player()
	{

	}
};

class Car
{

public:
	//멤버 함수 : 기능(method)
	//1. 어디 산하에 있는지 알 수 있어야 한다.
	//2. 객체가 필요하다.(어떤것에 기능을 적용해야하는지.)
	void SetInfo(int handle, int engine, int doors, int wheels)
	{
		_handle = handle;
		_engine = engine;
		_doors = doors;
		_wheels = wheels;
	}

	//get,set
	//1. 예외처리 가능.
	//2. debug
	void SetEngine(int engine)
	{
		_engine = engine;
	}
	int GetEngine() { return _engine; }

private:
	//멤버 변수 : 속성(attribute)
	//컨벤션
	int _handle;
	int _engine;
	int _doors;
	int _wheels;
};

int main()
{
	Car myCar;

	// :: 범위 지정 연산자
	//myCar.Car::SetEngine(3);  //이미 범위가 Car로 지정되어있기 때문.
	myCar.SetEngine(3);

	return 0;
}