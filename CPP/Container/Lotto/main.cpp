#include <iostream>

using namespace std;


//�ζ� ��ȣ �̱�
// ���� 1~45
// 7�� ������ ���ڸ� �̴´�.
// �ߺ����� �ʴ´�.
// �������� ����.

void Swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

int selected[7] = {};

void Sort(int arr[], int size)
{

}

void SetSelected()
{
	bool isGet[45] = { false };
	int arr[7] = { 0 };
	int selectNum = 0;
	while (selectNum < 7)
	{
		int chooseNum = rand() % 46;
		if (!isGet[chooseNum])
		{
			arr[selectNum] = chooseNum;
			isGet[chooseNum] = true;
			selectNum++;
		}
	}

	for (int i = 0; i < 7; i++)
	{
		cout << arr[i] << endl;
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	int aInt = 1;
	int bInt = 2;
	
	cout << aInt << " : " << bInt << endl;

	Swap(aInt, bInt);
	cout << aInt << " : " << bInt << endl;


	SetSelected();

	return 0;
}