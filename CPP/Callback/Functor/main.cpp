#include <iostream>

using namespace std;


//functor : 함수 객체?
//속성 기능을 가지고 메모리에 할당된 것.

struct Functor
{
	void operator()(void) //() : 함수 연산자 오버로딩
	{
		cout << "Hello World" << endl;
		PrintNum();
	}

	void PrintNum() { cout << num << endl; } //기능

	int num; //속성
	//함수인데 속성을 가질 수 있다.
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