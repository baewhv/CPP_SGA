#include <iostream>

using namespace std;


//���(const)�� ������ ����� ���ÿ� �ʱ�ȭ.

// ����(Reference)
// (�ڷ���)& (������) = (�ʱ�ȭ); => ����� ���ÿ� �ʱ�ȭ.

// C++
// - ����, ��Ī

// ������� ����
// - �����Ϳ� �����ϰ� ����. => ������ ����, ���� �����ϴ�.

// ������
// - ������ �б� �� ������ �����ϴ�. (Read And Write)

// ������
// 1. �ʱ�ȭ ����
// ptr : nullptr�� ����ų �� �ִ�. => �����Ȱ� ������ ǥ���� �� �ִ�.
// 2. ���� ��� ���� ����.
// 3. ������ ���� ����. => �� ����(call by value)�� ���°� �����ϴ�. null������ ������� �ʴ´�.

void AddOne(int& ref)
{
	ref++;
}



int main()
{
	int aInt = 1;
	int& aRef = aInt;

	int* aPtr = &aInt;

	aRef++;

	cout << aInt << endl;

	(*aPtr)++;

	cout << aInt << endl;

	return 0;
}