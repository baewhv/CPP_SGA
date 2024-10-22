#include <iostream>

using namespace std;

int main()
{
	const int a = 5;
	const int* ca = &a;
	//*ca += 5; //수정할 수 없는 값.

	int* cb = const_cast<int*>(ca);
	*cb += 5;
	cout << *cb << endl;
	cout << a << endl;  //디버그 상에서는 10인데 출력은 왜 5일까?
	cout << a << endl;  //컴파일러 최적화 관련 문제
	cout << *ca << a << endl;
	return 0;
}