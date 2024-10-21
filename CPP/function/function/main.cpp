#include <iostream>

using namespace std;

//함수 스택프레임
//함수란 : 함에다가 어떤 수를 넣고(input) 어떤 값을 반환받는 것(output)
//반환형식, 매개변수의 자료형, 개수, 함수 이름 => 함수 시그니쳐
int Add(int a, int b);	//함수 선언 => 함수 시그니쳐.
float Add(float a, float b); //함수 오버로딩 : 동일한 명칭의 함수가 다른 반환값과 매개변수를 가짐.
//int Add(int a, int b, int c = 1); // =1 -> 함수의 기본 인자. 맨 끝부터 차례대로 설정 가능. 하지만 매개변수 2개짜리와 구분이 모호해짐.
int Add(int a, int b, int c);
int Add(int a, int b, int c, int d, int e = 1); //

int Add(int a, int b);


void HelloWorld(void)	//void
{
	cout << "Hello World" << endl;
	return;
}

int Factorial(int n)	//재귀함수. 너무 많은 수를 넣으면 Stack overflow
{
	if (n == 1)
		return 1;
	return n * Factorial(n - 1);
}


int main()
{
	//난수 생성
	//시드 심기
	srand(time(NULL));
	//난수 생성.
	int randNum = rand();

	int answer = 0;

	cin >> answer;


	//main [반환주소값, 지역변수(aInt), 매개변수(void)]
	int aInt = Add(5, 3);
	int aInt5 = Add(1, 2, 3, 4, 1);
	int factorial = Factorial(51);

	cout << aInt << endl;
	return 0;
}

int Add(int a, int b)	//함수 정의
{
	//Add [반환주소값, 지역변수(cInt = 쓰레기값), 매개변수(a = 5, b = 3)]
	//main [반환주소값, 지역변수(aInt), 매개변수(void)]
	int cInt = a + b;

	//Add [반환주소값, 지역변수(cInt = 8), 매개변수(a = 5, b = 3)]
	//main [반환주소값, 지역변수(aInt), 매개변수(void)]
	return cInt; //반환값에 cInt 대입.
}

float Add(float a, float b)
{
	float cFloat = a + b;

	return cFloat;
}

int Add(int a, int b, int c)
{
	int dInt = a + b + c;
	return dInt;
}

int Add(int a, int b, int c, int d, int e)
{
	int answer = Add(a, b, c) + Add(d, e);
	return answer;
}

//과제 1.
//가위바위보 만들기.

//과제 2.
//스무고개 만들기.





