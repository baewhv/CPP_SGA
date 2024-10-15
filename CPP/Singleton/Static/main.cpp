#include <iostream>

using namespace std;


//static ����
// CODE
// DATA
// - ���� ����
// - ���� ����(static)
// ���α׷� ���� �� �Ҵ� / ����� ����
// STACK
// -����, �Ű�����, ��ȯ�ּҰ� => Stackframe
// HEAP
// - ����� �޸�

// - ���� / ����
// ���� : ������ �ð��� ����. ��Ÿ�ӿ� �������� �ʴ´�.
// ���� : ��Ÿ�ӿ� �����ǰ� �����ȴ�.

class Marine
{
public:
	// ��� �Լ��� ȣ�� ����
	// - ��� �������� �� �� �־���Ѵ�.
	// - ��ü�� �־�� �Ѵ�.

	void PrintInfo() 
	{
		cout << _hp << endl;
		cout << _atk << endl;
	}

	//���� ����Լ� : static ����Լ�
	//=> ����Լ��� �����Լ�ó�� ������ش�.
	//���� ��� �Լ��� ���� ��� �������� ������ ����� �� �ִ�.

	static void  Hello()
	{
		cout << "Hello World" << endl;
		//cout << _hp << endl; -> � ��ü���� ȣ���ߴ��� �� �� ����.
		//cout << _hp << endl;
		cout << _atk << endl;
	}

public:
	int _hp;

	//���� ����.
	static int _atk;
};

//���� ������ �������� �ʱ�ȭ���ش�.
int Marine::_atk = 0;


int main()
{
	Marine::_atk = 5;
	Marine::Hello(); //���� ����Լ��� ȣ��.

	Marine* arr[100];
	for (int i = 0; i < 100; i++)
	{
		arr[i] = new Marine();
		arr[i]->_hp = 50;
		arr[i]->_atk = 5;
	}

	for (int i = 0; i < 100; i++)
	{
		arr[i]->PrintInfo();
	}

	for (int i = 0; i < 100; i++)
	{
		delete arr[i];
	}

	return 0;
}