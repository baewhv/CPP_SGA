#include <iostream>

using namespace std;

// �������� ������
// *(����) => ���� ������
// int* ptr = 0x00; 
// ptr +1; �������� ���� ���� �� �ڷ����� ũ�⿡ �ٰ��Ͽ� �����Ѵ�.

//�ڷᱸ��(�����Ͱ� � �������� �̷�����ִ���)
//���� �迭
//1. �Ϸķ� ��ġ�Ǿ� �ִ� ����
//2. ���� �ڷ���.

//���� ���
//(�ڷ���) (�̸�)[(�迭 ����)] = {�ʱ�ȭ};
//�迭 ��ҿ� ����
//�迭�̸�[index] => �迭�� index��° ���ҿ� ����.(������)
//index : ����
//[] : ���� ���� ������. �迭�� ���� �ð��� ���(index * sizeof(datatype) + address)



int arr[5] = { 1,2,3,4,5 };

struct Player
{
	int item[100];
};

//�迭�� �̸��� �迭�� ù��° ������ �ּҰ��� �����ִ� �����Ϳ� �����ϰ� �۵��Ѵ�.


//���� �迭�� �Ű������� �ѱ� �� size�� ���� �Ѱܾ� �Ѵ�.
void PrintArr(int arr[], int size) //c++������ �迭�� �����͸� �ڵ����� �ٲ���.
{
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << endl;
		//cout << *(arr + i) << endl;//������ó�� �����ص� �����ϰ� �۵�.
	}

}

int main()
{
	//int aInt = 0;
	//int bInt = 1;	//�� ������ ���ӹ�ġ�Ǿ��ִٰ� ������ �� ���� ����.

	int* ptr = arr;

	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << endl;
	}

	cout << sizeof(arr)/sizeof(arr[0]) << endl;

	PrintArr(arr, sizeof(arr)/sizeof(int));


	return 0;
}