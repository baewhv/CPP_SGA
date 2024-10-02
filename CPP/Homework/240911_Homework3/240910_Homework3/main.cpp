#include<iostream>
using namespace std;



int main() {
	//literal 상수
	50;							//정수형 상수
	3.14;						//소수(double)형 상수
	1.414f;						//소수(float)형 상수
	'b';						//문자형 상수
	
	//심볼릭 상수
	const int constNum = 20;	//const 상수
	//변수 선언 앞에 const키워드를 붙여 상수임을 선언.
	//상수값을 넣어 초기화해야한다.
	//변수가 먼저 선언되어있다면 변수값으로도 초기화 가능하다.
	//런타임 중 상수로 설정된다.

#define defineNum 30		//매크로 상수
	//전처리 지시문(매크로)으로 값을 설정한다.
	//컴파일 중 해당 문구를 설정한 문구로 교체하는 식으로 상수처럼 사용할 수 있다.
	//둥일한 지시문에 다른 문구가 있으면 교체가 될 수 있고, 재정의 경고가 출력된다.
	//디버깅 중 해당 심볼로 식별할 수 없다.

	enum enumNum				//enum 상수
	{
		EnumNum1 = 1,
		EnumNum2 = 2,
		EnumNum3 = 2,
	};
	//enum키워드에 명칭을 지정하고 코드블럭에 키워드와 값을 입력한다.
	//정수형만 사용 가능하다.
	//키워드 중복 시 재정의 에러가 출력되며, 중복을 하여 사용을 원하는 경우 namespace를 사용해야 한다.
	//매직넘버를 사용하는데 있어 메모리 사용에 효과적이다.
		//컴파일 시 enum 키워드를 해당 상수로 바꿔 사용하기에 메모리에 할당되지 않는다.



	cout << "literal 상수 : " << 50 << endl;
	cout << "const 상수 : " << constNum << endl;
	cout << "define 상수 : " << defineNum << endl;
	cout << "enum 상수 : " << EnumNum2 << endl;


	//분기문
	int conditionA = 5;
	int conditionB = 6;
	int conditionC = 7;
	cout << "conditionA : " << conditionA << endl;
	cout << "conditionB : " << conditionB << endl;
	cout << "conditionC : " << conditionB << endl;

	if (conditionA < conditionB)	
	{
		//괄호 내 조건이 참인지 체크한다.
		//참일 경우 아래 식을 진행. 이후 조건을 체크하지 않는다.
		cout << "conditionA는 conditionB 보다 작습니다." << endl;
	}
	else if (conditionA < conditionB) 
	{
		//위 if문을 시행한 후 거짓일 경우 다음 조건을 체크한다.
		//참일 경우 아래 식을 진행.
		cout << "conditionA는 conditionB 보다 큽니다." << endl;
	}
	else                              
	{
		//위 조건문이 모두 거짓이면 항시 실행.
		//else 이후로 추가적인 조건은 걸지 못한다.
		cout << "conditionA와 conditionB는 같습니다." << endl;
	}
	if (conditionA != conditionC)	
	{
		//위 조건문과는 별개의 조건문.
		cout << "conditionA와 conditionB는 같습니다." << endl;
	}

	switch (conditionA) //분기를 체크할 값을 넣는다.
	{
	case 4:				//조건을 설정한다.
		cout << "conditionA는 4입니다." << endl;
		break;
	case 5:
		//조건이 일치할 경우 해당 내용부터 break가 나올 때 까지 코드를 실행한다.
		cout << "conditionA는 5입니다." << endl;
	case 6:
		cout << "conditionA는 6은 아닌데 5에서 정지되지 않아 식이 진행되었습니다." << endl;
		break;
	default:
		//조건이 일치하는 값이 없을 경우 default를 거친다.
		cout << "conditionA 조건과 일치하는 값이 없었습니다." << endl;
		break;
	}


	//반복문
	for (int i = 0; i < 10; i++)
	{
		//초기 조건, 종료조건, 증감 연산자를 이용하여 작업을 반복한다.
		cout << "for문 " << i << "회 반복" << endl;
		cout << i << endl;

		if (i == 4)
			break;   //break를 통해 반복을 중단할 수 있다.
	}


	int i = 0;
	while (i < 10)
	{
		//조건이 참인 경우에 작업을 진행한다.
		cout << "while문 " << i++ << "회 반복" << endl;
		if (i == 4)
			break;   //break를 통해 반복을 중단할 수 있다.
	}
	
	i = 0;
	do
	{
		//작업을 먼저 진행하고 조건을 체크한다.
		cout << "do while문 " << i++ << "회 반복" << endl;
		if (i == 4)
			break;
	} while (i < 10); //조건이 참이면 작업을 반복한다.

	//포인터에 대해 조사
	
	// 자료는 값과 이름, 자료형, 메모리 주소가 저장된다.
	// 보통은 데이터의 값을 이용하지만 주소를 이용할 때 포인터를 사용한다.
	// 
	// 사용하는 이유
	// - 지역변수는 해당 지역(코드블럭)이 종료되면 해당 변수를 재사용할 수 없지만 주소를 저장만 해두면 사용할 수 있다.
	// - 선언해둔 코드블럭 외에서 주소값을 전달하여 다른 코드블럭에서 사용할 수 있다.
	// - 프로그램이 실행중일때 추가적인 변수를 할당할 수 있다.
	// - 함수를 사용할 때 크거나 복잡한 구조의 데이터를 주소값만 전달하여 낭비를 막을 수 있다.
	// 
	// 사용 방법
	// int* aPtr;
	// 변수의 자료형 다음에 *을 붙이는 것으로 포인터를 생성한다.
	// 생성 시 값을 넣지 않고 생성할 수 있으며, 쓰레기 값이 들어간다.
	// 다만 초기화하지 않은 포인터는 사용할 수 없다.
	//
	// int* aPtr = new int(1);
	// 초기화는 new라는 키워드를 이용하여 초기화 하거나
	// 
	// int b = 10;
	// int* bPtr = &b;
	// 동일한 데이터 타입의 변수에 주소 연산자를 이용해 주소값을 넣어 초기화 할 수 있다.
	// 
	// 
	// cout << "함수 b의 값 : " << b << endl;
	// cout << "함수 b의 주소 : " << &b << endl;
	// 일반 변수는 변수명을 그대로 써 값을 이용하고
	// &를 앞에 붙여 주소를 이용한다.
	// 
	// cout << "함수 a의 값 : " << *a << endl;
	// cout << "함수 a의 주소 : " << a << endl;
	// 포인터는 포인터명 앞에 *을 붙여 값을 가져오고 
	// 포인터명을 바로 사용해 주소를 이용한다.
	//
	// aPtr += 10;
	// 포인터의 주소의 값을 수동으로 변경할 수는 있지만 기존 값과의 연결은 끊어져 가비지 데이터가 되고, 변경된 포인터는 잘못된 값을 가져올 수 있다.
	// 올바르게 할당된 주소만 대입하는것이 바람직하다.


	return 0;
}

