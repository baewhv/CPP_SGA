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

int main()
{
	Functor functor;
	functor.num = 1;
	functor();

	functor.num = 2;
	functor();

	functor.num = 3;
	functor();

	return 0;
}