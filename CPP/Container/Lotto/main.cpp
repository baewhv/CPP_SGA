#include <iostream>

using namespace std;


//로또 번호 뽑기
// 범위 1~45
// 7개 무작위 숫자를 뽑는다.
// 중복되지 않는다.
// 오름차순 정렬.

int selected[7] = {};

void Swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

void Shuffle(int arr[], int size, int count)
{
	for (int i = 0; i < count; i++)
	{
		int leftIndex = rand() % size;
		int rightIndex = rand() % size;

		Swap(arr[leftIndex], arr[rightIndex]);
	}
}


void Sort(int arr[], int size)
{

}

//순차정렬 SequentialSort
void SequentialSort(int arr[], int size)
{
	// 시간 복잡도가 n^2.
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[i] < arr[j])
			{
				Swap(arr[i], arr[j]);
			}
		}
	}
}

void SelectedSort(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int bestIndex = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[bestIndex] > arr[j])
			{
				bestIndex = j;
			}
		}
		if (i == bestIndex)
			continue;
		Swap(arr[i], arr[bestIndex]);

	}
}

void BubbleSort(int arr[], int size)
{
	for (int i = size; i > 0; i--)
	{
		for (int j = 0; j < i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
				Swap(arr[j], arr[j + 1]);
		}
	}
}

void SetSelected()
{
	int arr[45] = { };
	for (int i = 0; i < 45; i++)
	{
		arr[i] = i + 1;
	}

	Shuffle(arr, 45, 10000);

	for (int i = 0; i < 7; i++)
	{
		//cout << arr[i] << endl;
		selected[i] = arr[i];
	}
	//SequentialSort(selected, 7);
	BubbleSort(selected, 7);
	for (int i = 0; i < 7; i++)
	{
		cout << selected[i] << endl;
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	//int aInt = 1;
	//int bInt = 2;
	//
	//cout << aInt << " : " << bInt << endl;

	//Swap(aInt, bInt);
	//cout << aInt << " : " << bInt << endl;


	SetSelected();

	return 0;
}