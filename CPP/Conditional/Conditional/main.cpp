#include <iostream>

using namespace std;

//과제2
//분기문

//if
// if(조건식)
// {
//		실행문
// }
// else if (조건식)
// {
//		실행문
// }
// else
// {
//		실행문
// }
//switch
//for
//while


//과제3


int main()
{
#pragma region hi
#pragma region hello
	int aInt = 5;
	if (aInt > 5)
	{
		cout << "5보다 큼" << endl;
	}
	else if (aInt < 5)
	{
		cout << "5보다 작음" << endl;
	}
	else
	{
		cout << "a 는 5" << endl;
	}

#pragma endregion hi
#pragma endregion

	return 0;
}