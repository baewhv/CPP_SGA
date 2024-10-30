#include <iostream>
#include <vector>
#include <list>
using namespace std;

#include "myVector.h"



//container : c++ �ڷᱸ��
//vector, list : ���� �ڷᱸ��


//���� �迭
int arr[5] = { 1,2,3,4,5 };
//data
//[~~~][1,2,3,4,5[6]~~~] ���� ���� ������ �ϰԵǸ� ������ �ȴ�.
//

//2���� �迭�� �Ű����� ���
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

//�ζǹ�ȣ �̱�


// iterator : ��ȸ��
// c++ ���̺귯������ �����ϴ� �����̳ʵ��� �� ��Ⱥ�� �������� ��ȸ�� �����ϴ�.
// stl���� �����ϴ� �˰��� �Լ���, �����̳��� ����Լ����� ����� �� ���δ�.

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
	//1,2,3,4,5,6���� �޸𸮿� 1�ڷ� �þ�������.
	int* ptr = &arr[0][0];

	//cout << *(ptr + 1) << endl;
	}

	{
		//vector : ���� �迭, ���� �迭 <-> �����迭
		//1. ���̰� �������� ���� �� �ִ�.

		vector<int> v;

		//���뷮�� ������ �� ���� ������ �����ϴ� ������ �ֱ⿡ �׸�ŭ �޸𸮰� ���� �ʿ��� �� �ִ�.

		//v.reserve(1000); //�ʱ� ���뷮�� �̸� 1000���� �÷�����.
		v.resize(1000);

		//�޸� ����ȭ

		for (int i = 0; i < 1000; i++)
		{
			v.push_back(i);
			//cout << "Capacity : " << v.capacity() << endl;
			//cout << "Size : " << v.size() << endl;
		}
	}




	vector<int> v;
	v.push_back(3);
	v.push_back(5);
	v.push_back(1);
	v.push_back(16);
	v.push_back(222);
	v.push_back(34);
	v.push_back(68);

	//1. �ε����� Ȱ���� ��ȸ.
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	vector<int>::iterator vIter = v.begin();
	//2. iterator�� �̿��� ��ȸ
	for (vIter; vIter != v.end(); vIter++)
	{
		cout << *vIter << endl;
	}

	vector<int>::iterator insertIter = v.begin() + 3;

	vector<int>::iterator resultIter = v.insert(insertIter, 10);

	v.erase(resultIter + 1);

	return 0;
}