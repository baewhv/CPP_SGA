#include <iostream>

using namespace std;

void Swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

void Sort(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (arr[i] > arr[j])
			{
				swap(arr[i], arr[j]);
			}
		}
	}
}

void PrintArr(int arr[], int size)
{

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}

void SetSelected()
{
	bool isGet[45] = { false };
	int arr[7] = { 0 };
	int selectNum = 0;
	while (selectNum < 7)
	{
		int chooseNum = rand() % 45;
		if (!(isGet[chooseNum]))
		{
			arr[selectNum] = chooseNum + 1;
			isGet[chooseNum] = true;
			selectNum++;
		}
	}
	cout << "Seletc Numbers" << endl;
	PrintArr(arr, 7);
	Sort(arr, 7);
	cout << endl << "Sort Numbers" << endl;
	PrintArr(arr, 7);
}

int main()
{
	srand(time(NULL));
	SetSelected();

	return 0;
}