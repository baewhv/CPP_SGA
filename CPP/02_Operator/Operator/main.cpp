#include <iostream>

using namespace std;

//과제
//상수를 표시하는 3가지? const static?

//CODE

//DATA : 전역변수, 정적변수
//STACK : [반환주소값][지역변수][매개변수] => 스택프레임
//HEAP : ???

//aInt + bInt : aInt와 bInt를 더한 결과값을 임시로 반환.
//aInt - bInt : aInt와 bInt를 뺀 결과값을 임시로 반환.
//aInt * bInt : aInt와 bInt를 곱한 결과값을 임시로 반환.
//float * float : 소수점의 곱.
// 
//aInt / bInt : aInt와 bInt를 나눈 결과값 중 몫을 임시로 반환.
//aInt % bInt : aInt와 bInt를 나눈 결과값 중 나머지를 임시로 반환.
//float / float : 
// = : 대입 연산자
// += : 증감 연산자

// 단항 연산자 (int형에서만.)
//     전위 연산자
//++aInt : a원본에 1을 더해 반환한다.
//     후위 연산자
//aInt++ : 해당 식 이후 1을 더해 반환한다.

//비교 연산자 (반환값 bool)
//<. <= , >, >=, ==, !=

//논리 연산자 (bool 끼리 비교)
// ! (단항 / NOT) : true -> false / false -> true;
// 
// && (이항 / AND) 
// || (이항 / OR)

//비트 연산자 (비트간 비교)
// << , >> , &, |, ^
// << 왼쪽 쉬프트 연산.
//    옮긴 후 0으로 채워짐.
//    unsinged 형식을 많이 쓴다.?
// >> 오른쪽 쉬프트 연산.
//    맨 오른쪽 비트가 버려진다.
//    부호 비트는 유지된다.
// &  비트 and 연산.
//    같은 자리의 비트가 서로 1이면 1, 나머지 0
// |  비트 or 연산.
//    같은 자리의 비트 중 하나라도 1이면 1.
// ^  비트 XOR 연산. -> 암호쪽에서 쓴다?
//    같으면 0, 다르면 1


unsigned char bitFlags;

unsigned char  stun =  0b0001;
unsigned char  airborne =  0b0010;
unsigned char  rooted = 0b0100;
unsigned char  slow = 0b1000;
int main()
{
	int aInt = 10;
	int bInt = 3;
	{
		
		int cInt = aInt % bInt;

		aInt %= 5;
		cout << (aInt = bInt) << endl;

		

	}
	char aChar = 'b';
	aChar++;

	aInt = 0;
	bInt = 3;

	aInt++;
	//전위 연산 : 
	cout << ++aInt << endl;
	cout << aInt++ << endl;

	aInt = 3;
	bInt = 5;
	
	bool check1 = (aInt < bInt); // 3 < 5 true
	bool check2 = (aInt == bInt); // 3 != 5 false
	bool check3 = check1 < check2; // 1 < 0 false?

	bool check4 = (check1 && check3); // true && false = false;
	bool check5 = !check4 + 10;       // ture + 10 = true;
	bool check6 = check4 || check5 || check1 || check3 || check2; // true


	aInt = 3;
	bInt = 6;


	bitFlags = stun | slow;
	
	if (bitFlags & stun)
	{
		cout << "기절" << endl;
	}

	bitFlags = bitFlags | !slow; //둔화? 1110
	bitFlags = bitFlags | rooted; //속박

	if (bitFlags & (stun | rooted))
	{
		cout << "기절 / 속박" << endl;
	}
	
	return 0;
}