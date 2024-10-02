#include<iostream>

using namespace std;

/*
Pointer
==> mean : ����Ű�� ��.
==> C++  : �ּҰ��� ����ִ� ����.
(DataType)* (ValueName) = (Init);

&(ValueName) : �ּ� ������ == ������ �ּҰ��� ����
*(ValueName) : ���� ������ == ��Ż������
�ڷ����� ���� : �ּҸ� Ÿ�� ���� ��, � �ڷ����� �ִ��� �˷��ִ� ��Ʈ.
 

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
	cout << *aPtr << endl; //�ּ��� ��
	cout << aPtr << endl;	//�ּ�
	cout << &aPtr << endl;	//�������� �ּ�

	cout << aInt << endl;
	cout << &aInt << endl;


	AddOne(aInt);
	//main	[return][local : aInt(1)]	[value : ]
	cout << aInt << endl;
	return 0;
}