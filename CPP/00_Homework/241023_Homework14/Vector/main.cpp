#include <iostream>

using namespace std;

#include "myVector.h"

int main()
{
	myVector<int> v;
	int makeNum = 9;
	for (int i = 0; i < makeNum; i++)
	{
		v.PushBack(i);
	}

	cout << v.Capacity() << endl;
	cout << v.Size() << endl;
	cout << "___________________" << endl;

	for (int i = 0; i < makeNum; i++)
	{
		cout << v[i] << endl;
	}

	v.Insert(5, 1000);
	makeNum++;
	cout << "___________________insert" << endl;
	for (int i = 0; i < makeNum; i++)
	{
		cout << v[i] << endl;
	}

	return 0;
}