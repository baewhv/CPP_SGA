#include <iostream>


//const_cast
//������ const�� ������ �� �ִ�.

using namespace std;


int main()
{
	const int a = 5;
	const int* ca = &a;
	//*ca += 5;
	int* cb = const_cast<int*>(&a);
	*cb += 5;
	cout << *cb << endl;
	cout << a << endl;

	return 0;
}