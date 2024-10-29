#include <list>
#include <iostream>

#include "myList.h"

using namespace std;

int main()
{
	myList<int> mList;
	mList.Push_back(5);
	mList.Push_back(3);
	mList.Push_back(2);
	mList.Push_back(7);
	mList.Push_back(8);
	mList.Push_front(10);
	cout << "Push back & front" << endl;
	mList.PrintData();

	mList.Pop_back();
	mList.Pop_front();
	cout << endl << "Pop back & front" << endl;
	mList.PrintData();

	mList.Insert(mList.findNode(1), 100);
	cout << endl << "Insert. index : 1, data : 100" << endl;
	mList.PrintData();

	mList.DeleteNode(mList.findNode(3));
	cout << endl << "Delete. index : 3" << endl;
	mList.PrintData();
}