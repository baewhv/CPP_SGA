#include <iostream>
#include <vector>
#include <list>


using namespace std;

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

int main()
{

	{
	int arr[2][3] = { {1,2,3},{4,5,6} };
	//1,2,3,4,5,6���� �޸𸮿� 1�ڷ� �þ�������.
	int* ptr = &arr[0][0];

	cout << *(ptr + 1) << endl;
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
			cout << "Capacity : " << v.capacity() << endl;
			cout << "Size : " << v.size() << endl;
		}
	}

	return 0;
}