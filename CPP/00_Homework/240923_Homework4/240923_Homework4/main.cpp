#include <iostream>

using namespace std;

int main()
{
	int remain = 9;
	int min = 0;
	int max = 500;
	srand(time(NULL));
	int answer = rand() % 500 + 1;
	cout << "9���� ��ȸ���� 0~500 ���� ���� 1���� �����ּ���."<< endl;

	while (true)
	{

		if (remain <= 0)
		{
			cout << "���ӿ��� �й��Ͽ����ϴ�." << endl;
			break;
		}
		cout << "���ڸ� �Է����ּ���. ����Ƚ�� : " << remain << endl;
		int a = 0;
		cin >> a;

		if (a < min || a > max)
		{
			cout << "������ ������ϴ�." << endl;
			continue;
		}
		else if (a < answer)
		{
			cout << "up" << endl;
			remain--;
			continue;
		}
		else if (a > answer)
		{
			cout << "down" << endl;
			remain--;
			continue;
		}
		else
		{
			cout << "�����Դϴ�." << endl;
			break;
		}
	}
}