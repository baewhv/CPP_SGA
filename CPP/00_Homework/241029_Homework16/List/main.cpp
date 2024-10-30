#include <list>
#include <iostream>

#include "myList.h"

using namespace std;

int main()
{
	myList<int> mList;
	mList.push_back(5);
	mList.push_back(3);
	mList.push_back(2);
	mList.push_back(7);
	mList.push_back(8);
	mList.push_front(10);

	for (auto it = mList.begin(); it != mList.end(); it++)
	{
		cout << *it << endl;
	}
}