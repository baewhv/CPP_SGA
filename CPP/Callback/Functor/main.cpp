#include <iostream>

using namespace std;


//functor : �Լ� ��ü?
//�Ӽ� ����� ������ �޸𸮿� �Ҵ�� ��.

struct Functor
{
	void operator()(void) //() : �Լ� ������ �����ε�
	{
		cout << "Hello World" << endl;
		PrintNum();
	}

	void PrintNum() { cout << num << endl; } //���

	int num; //�Ӽ�
	//�Լ��ε� �Ӽ��� ���� �� �ִ�.
};

struct Functor2
{
	bool operator()(int num)
	{
		if (num == compareNum)
		{
			return true;
		}
		return false;
	}
	int compareNum;
};

int main()
{
	Functor functor;
	functor.num = 1;
	functor();

	functor.num = 2;
	functor();

	functor.num = 3;
	functor();

	Functor2 functor2;
	functor2.compareNum = 5;

	int aInt = 12;

	if (functor2(12))
		cout << "aInt�� " << functor2.compareNum << "�� �����ϴ�." << endl;
	else
		cout << "aInt�� " << functor2.compareNum << "�� �ٸ��ϴ�." << endl;

	return 0;
}