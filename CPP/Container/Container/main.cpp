#include <iostream>
#include <vector>
#include <list>
using namespace std;

//
// #include "myVector.h"

#include "myList.h"

//container : c++ 자료구조
//vector, list : 선형 자료구조


//정적 배열
int arr[5] = { 1,2,3,4,5 };
//data
//[~~~][1,2,3,4,5[6]~~~] 선언 이후 증가를 하게되면 오염이 된다.
//

//2차원 배열의 매개변수 사용
void PrintTwoD(int arr[][3], int ySize)
{
	for (int y = 0; y < ySize; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			cout << arr[y][x];
		}
	}
}

//로또번호 뽑기


// iterator : 순회자
// c++ 라이브러리에서 제공하는 컨테이너들을 이 수횐자 문법으로 순회가 가능하다.
// stl에서 제공하는 알고리즘 함수들, 컨테이너의 멤버함수들을 사용할 때 쓰인다.

template<typename Container, typename Iter>
void PrintContainer(Container container)
{
	Iter iter;

	iter = container.begin();

	for (iter; iter != container.end(); iter++)
	{
		cout << *iter << endl;
	}
}


int main()
{

	{
	int arr[2][3] = { {1,2,3},{4,5,6} };
	//1,2,3,4,5,6으로 메모리에 1자로 늘어져있음.
	int* ptr = &arr[0][0];

	//cout << *(ptr + 1) << endl;
	}
	/*
	{
		//vector : 동적 배열, 가변 배열 <-> 정적배열
		//1. 길이가 동적으로 변할 수 있다.

		vector<int> v;

		//수용량이 증가할 때 기존 내용을 복사하는 과정이 있기에 그만큼 메모리가 많이 필요할 수 있다.

		//v.reserve(1000); //초기 수용량을 미리 1000개로 늘려놓음.
		v.resize(1000);

		//메모리 단편화

		for (int i = 0; i < 1000; i++)
		{
			v.push_back(i);
			//cout << "Capacity : " << v.capacity() << endl;
			//cout << "Size : " << v.size() << endl;
		}
	}
	*/

	cout << "list" << endl;

	myList<int> v;
	v.push_back(3);
	v.push_back(5);
	v.push_back(1);
	v.push_back(16);
	v.push_back(222);
	v.push_back(34);
	v.push_back(68);



	//1. 인덱스를 활용한 순회.
	//for (int i = 0; i < v.size(); i++)
	//{
	//	cout << *v.begin() << endl;
	//}

	myList<int>::Iterator vIter = v.begin();
	//2. iterator를 이용한 순회
	for (vIter; vIter != v.end(); vIter++)
	{
		cout << *vIter << endl;
	}



	return 0;
}