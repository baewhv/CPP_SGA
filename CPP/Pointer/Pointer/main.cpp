#include<iostream>

using namespace std;

/*
Pointer
==> mean : 가르키는 것.
==> C++  : 주소값을 담고있는 변수.
(DataType)* (ValueName) = (Init);

&(ValueName) : 주소 연산자 == 변수의 주소값을 추출
*(ValueName) : 간접 연산자 == 포탈연산자
자료형의 목적 : 주소를 타고 들어갔을 때, 어떤 자료형이 있는지 알려주는 힌트.
 

*/


void AddOne(int num)
{
	//AddOne[return][local : ]			[value : num(1)]
	//main	[return][local : aInt(1)]	[value : ]
	
	num++;
	//AddOne[return][local : ]			[value : num(2)]
	//main	[return][local : aInt(1)]	[value : ]
}
void AddOne(int* ptr)
{

//AddOne	[return]	[local : ]			[value : ptr(&aInt)]
//main		[return]	[local : aInt(1)]	[value : ]

	(*ptr)++;

//AddOne	[return]	[local : ]			[value : ptr(&aInt)]
//main		[return]	[local : aInt(2), aPtr(&aInt)]	[value : ]
}


int main()
{

	int aInt = 1;
	//main	[return][local : aInt(1)]	[value : ]
	int* aPtr;
	aPtr = &aInt;
	cout << *aPtr << endl; //주소의 값
	cout << aPtr << endl;	//주소
	cout << &aPtr << endl;	//포인터의 주소

	cout << aInt << endl;
	cout << &aInt << endl;


	AddOne(aInt);
	//main	[return][local : aInt(1)]	[value : ]
	cout << aInt << endl;
	return 0;
}