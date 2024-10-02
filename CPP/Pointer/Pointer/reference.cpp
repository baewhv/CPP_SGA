#include <iostream>

using namespace std;


//상수(const)도 무조건 선언과 동시에 초기화.

// 참조(Reference)
// (자료형)& (변수명) = (초기화); => 선언과 동시에 초기화.

// C++
// - 별명, 별칭

// 어셈블리어 관점
// - 포인터와 동일하게 동작. => 원본에 접근, 수정 가능하다.

// 공통정
// - 원본에 읽기 및 수정이 가능하다. (Read And Write)

// 차이점
// 1. 초기화 여부
// ptr : nullptr을 가리킬 수 있다. => 참조된게 없음을 표시할 수 있다.
// 2. 참조 대상 변경 여부.
// 3. 참조는 쓰기 쉽다. => 값 전달(call by value)와 형태가 동일하다. null참조를 허용하지 않는다.

void AddOne(int& ref)
{
	ref++;
}



int main()
{
	int aInt = 1;
	int& aRef = aInt;

	int* aPtr = &aInt;

	aRef++;

	cout << aInt << endl;

	(*aPtr)++;

	cout << aInt << endl;

	return 0;
}