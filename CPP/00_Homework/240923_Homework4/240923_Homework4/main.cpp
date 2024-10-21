#include <iostream>

using namespace std;

int main()
{
	int remain = 9;
	int min = 0;
	int max = 500;
	srand(time(NULL));
	int answer = rand() % 500 + 1;
	cout << "9번의 기회동안 0~500 사이 숫자 1개를 맞춰주세요."<< endl;

	while (true)
	{

		if (remain <= 0)
		{
			cout << "게임에서 패배하였습니다." << endl;
			break;
		}
		cout << "숫자를 입력해주세요. 남은횟수 : " << remain << endl;
		int a = 0;
		cin >> a;

		if (a < min || a > max)
		{
			cout << "범위를 벗어났습니다." << endl;
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
			cout << "정답입니다." << endl;
			break;
		}
	}
}