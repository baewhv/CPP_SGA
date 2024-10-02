#include <iostream>

using namespace std;
// class
// �������� : ������� ����
// ��ü���� : ��ü�� �Ӽ��� ����� ���� �Ϳ� ������ �ΰ� ���α׷����ϴ� ��.
// ��ü : �Ӽ� + ��� -> �޸𸮿� �Ҵ�Ǿ��ִ� ��.

// ��ü ������ 3�Ӽ�
// ���м�(ĸ��ȭ)
//	- ���� ������
//  - public : ��� ������ ��ü�� ����� ����, ���� ����.
//  - private : Ŭ���� �ȿ����� ����� ����, ���� ����.
//  - protected : Ŭ������ �ڽĵ鿡�Լ��� ����, ��������.
// ��Ӽ�
// ������(Polymorphism) => ���°� �پ��ϴ�.


//�����ڷ������� �ַ� ���.
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
	//��� �Լ� : ���(method)
	//1. ��� ���Ͽ� �ִ��� �� �� �־�� �Ѵ�.
	//2. ��ü�� �ʿ��ϴ�.(��Ϳ� ����� �����ؾ��ϴ���.)
	void SetInfo(int handle, int engine, int doors, int wheels)
	{
		_handle = handle;
		_engine = engine;
		_doors = doors;
		_wheels = wheels;
	}

	//get,set
	//1. ����ó�� ����.
	//2. debug
	void SetEngine(int engine)
	{
		_engine = engine;
	}
	int GetEngine() { return _engine; }

private:
	//��� ���� : �Ӽ�(attribute)
	//������
	int _handle;
	int _engine;
	int _doors;
	int _wheels;
};

int main()
{
	Car myCar;

	// :: ���� ���� ������
	//myCar.Car::SetEngine(3);  //�̹� ������ Car�� �����Ǿ��ֱ� ����.
	myCar.SetEngine(3);

	return 0;
}