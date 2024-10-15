#include <iostream>
using namespace std;

// CODE
// 
// DATA
// 전역변수 (정적변수)
// 생성주기 : 프로그램 실행 시 할당. 프로그램 종료 시 해제.
// 장점 : 어디서든 접근이 가능하다.
// 단점 : 종료 전 까지 해제 불가능.
//       영역의 크기가 작다.
// 
// STACK
// (지역변수, 반환주소값, 매개변수) => 스택프레임
// 생성 주기 : 함수 호출 시 할당. 함수 종료 시 해제.
// 장점, 단점 : 함수 밖으로 꺼낼 수 없다.
// 
// HEAP
// 프로그래머의 영역.
// 생성주기 : 프로그래머가 직접 생성, 소멸을 만들어야함.
// C스타일
// malloc / free
// C++스타일
// new  / delete
// new[] / delete[] -> 원하는 용량 할당.

//동적할당

class Player
{
public:
	Player() {}
	Player(int hp, int atk) : _hp(hp), _atk(atk) {}

	int _hp;
	int _atk;
};



int main()
{
	/* C스타일 동적할당
	//void* : 타고 들어가면 무언가가 있지만 무엇인지 알 수 없다.
	void* ptr = malloc(100); //Heap 영역에 100byte를 할당 받고 그 위치를 가리키는 포인터 반환.
	int* intPtr = (int*)ptr;

	for (int i = 0; i < 25; i++)
	{
		*(intPtr + i) = i + 1;
	}

	free(ptr);
	*/ //C스타일 동적할당


	int* intPtr = new int();			//변수 동적할당
	Player* pPtr = new Player(10, 2);	//Class 동적할당
	char* charPtr = new char[100];


	Player* pArr = new Player[100];
	//stack에서 주소값인 4byte만 잡아먹으나 힙 영역에 한번에 넣기가 어렵다.

	Player* pPtrArr[100] = { nullptr };
	
	for (int i = 0; i < 100; i++)
	{
		pPtrArr[i] = new Player();
	}


	int* tempPtr = (int*)charPtr;
	*tempPtr = 1;



	delete[] pArr;
	delete[] charPtr;
	delete intPtr;
	delete pPtr;


	return 0;
}