#include <iostream>


//const_cast
//변수에 const를 제거할 수 있다.

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