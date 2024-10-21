#include <iostream>

using namespace std;

bool aBool = 1;

char aChar = 'A';

int aInt = -50;
unsigned int uInt = 100;
__int64 aInt64 = -12354548763;
unsigned __int64 uInt64 = 9999999999999999999;

float aFloat = 3.1415926535f;
double aDouble = 3.1415926535;


struct StructForm
{
	int a = 50;
	int b = 30;
	__int64 c= 12354;
	char d = 64; //빈 공간이 생김.
	long long e = 12354;
	long f;
} aStruct;


int main()
{
	cout << "aBool = " << aBool << " aBool의 크기 : " << sizeof(aBool) << endl;
	cout << "aChar = " << aChar << " aChar의 크기 : " << sizeof(aChar) << endl;
	cout << "aInt = " << aInt << " aInt의 크기 : " << sizeof(aInt) << endl;
	cout << "uInt = " << uInt << " uInt의 크기 : " << sizeof(uInt) << endl;
	cout << "aInt64 = " << aInt64 << " aInt64의 크기 : " << sizeof(aInt64) << endl;
	cout << "uInt64 = " << uInt64 << " uInt64의 크기 : " << sizeof(uInt64) << endl;

	cout << "aFloat = " << aFloat << " aFloat의 크기 : " << sizeof(aFloat) << endl;
	cout << "aDouble = " << aDouble << " aDouble의 크기 : " << sizeof(aDouble) << endl;
	cout << "aStruct.a = " << aStruct.a << endl;
	cout << "aStruct.b = " << aStruct.b << endl;
	cout << "aStruct.c = " << aStruct.c << endl;
	cout << "aStruct.d = " << aStruct.d << endl;
	cout << "aStruct.e = " << aStruct.e << endl;
	cout << "aStruct.f = " << aStruct.f << endl;
	cout << "aStruct의 크기 : " << sizeof(aStruct) << endl;

	

	return 0;
}