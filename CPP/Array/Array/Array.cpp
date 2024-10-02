#include <iostream>

using namespace std;

// 포인터의 연산자
// *(변수) => 간접 연산자
// int* ptr = 0x00; 
// ptr +1; 포인터의 덧셈 연산 시 자료형의 크기에 근거하여 덧셈한다.

//자료구조(데이터가 어떤 형식으로 이루어져있는지)
//정적 배열
//1. 일렬로 배치되어 있는 구조
//2. 같은 자료형.

//선언 방법
//(자료형) (이름)[(배열 개수)] = {초기화};
//배열 요소에 접근
//배열이름[index] => 배열의 index번째 원소에 접근.(정수만)
//index : 색인
//[] : 임의 접근 연산자. 배열의 접근 시간은 상수(index * sizeof(datatype) + address)



int arr[5] = { 1,2,3,4,5 };

struct Player
{
	int item[100];
};

//배열의 이름은 배열의 첫번째 원소의 주소값을 갖고있는 포인터와 동일하게 작동한다.


//정적 배열은 매개변수로 넘길 때 size도 같이 넘겨야 한다.
void PrintArr(int arr[], int size) //c++에서는 배열을 포인터를 자동으로 바꿔줌.
{
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << endl;
		//cout << *(arr + i) << endl;//포인터처럼 변경해도 동일하게 작동.
	}

}

int main()
{
	//int aInt = 0;
	//int bInt = 1;	//두 변수는 연속배치되어있다고 보장할 수 없는 상태.

	int* ptr = arr;

	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << endl;
	}

	cout << sizeof(arr)/sizeof(arr[0]) << endl;

	PrintArr(arr, sizeof(arr)/sizeof(int));


	return 0;
}