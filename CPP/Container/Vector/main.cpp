#include <iostream>

using namespace std;

#include "myVector.h"

int main()
{
	myVector v;
	
	for (int i = 0; i < 100; i++)
	{
		v.PushBack(i);
	}

	cout << v.Capacity() << endl;
	cout << v.Size() << endl;
	cout << "___________________" << endl;

	for (int i = 0; i < 100; i++)
	{
		cout << v[i] << endl;
	}

	return 0;
}