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
	char d = 64; //�� ������ ����.
	long long e = 12354;
	long f;
} aStruct;


int main()
{
	cout << "aBool = " << aBool << " aBool�� ũ�� : " << sizeof(aBool) << endl;
	cout << "aChar = " << aChar << " aChar�� ũ�� : " << sizeof(aChar) << endl;
	cout << "aInt = " << aInt << " aInt�� ũ�� : " << sizeof(aInt) << endl;
	cout << "uInt = " << uInt << " uInt�� ũ�� : " << sizeof(uInt) << endl;
	cout << "aInt64 = " << aInt64 << " aInt64�� ũ�� : " << sizeof(aInt64) << endl;
	cout << "uInt64 = " << uInt64 << " uInt64�� ũ�� : " << sizeof(uInt64) << endl;

	cout << "aFloat = " << aFloat << " aFloat�� ũ�� : " << sizeof(aFloat) << endl;
	cout << "aDouble = " << aDouble << " aDouble�� ũ�� : " << sizeof(aDouble) << endl;
	cout << "aStruct.a = " << aStruct.a << endl;
	cout << "aStruct.b = " << aStruct.b << endl;
	cout << "aStruct.c = " << aStruct.c << endl;
	cout << "aStruct.d = " << aStruct.d << endl;
	cout << "aStruct.e = " << aStruct.e << endl;
	cout << "aStruct.f = " << aStruct.f << endl;
	cout << "aStruct�� ũ�� : " << sizeof(aStruct) << endl;

	

	return 0;
}