#include <iostream>

using namespace std;

bool checkRemain(const int remain)
{
	if (remain <= 0)
	{
		cout << "No remains. You lose." << endl;
		return false;
	}
	else
	{
		if(remain != 1)
			cout << "Remains : " << remain << endl;
		else
			cout << "Remain : " << remain << endl;
		return true;
	}
}

int setRandomNum(int min, int max)
{
	srand(time(NULL));
	return rand() % (max - min + 1);
}

void getIntMessage(int* msg)
{
	cout << "Please input your number." << endl;
	cin >> *msg;
}

bool checkAnswer(int* value, int& remain, int* answer, int min, int max)
{
	if (*value < min || *value > max)
	{
		cout << "Out of range." << endl;
	}
	else if (*value < *answer)
	{
		cout << "Incorrect. Increase your number." << endl;
		remain--;
	}
	else if (*value > *answer)
	{
		cout << "Incorrect. Decrease your number." << endl;
		remain--;
	}
	else
	{
		cout << "Correct!" << endl;
		return true;
	}
	return false;
}

void nineValley(int remain, int min, int max)
{
	int* answer = new int(setRandomNum(min, max));
	bool* isWin = new bool(false);
	cout << "Please match one number between 0 and 500 for 9 chances." << endl;
	int* msg = new int(0);
	cout << *answer << endl;
	while (!(*isWin) && checkRemain(remain))
	{
		getIntMessage(msg);
		*isWin = checkAnswer(msg, remain, answer, min, max);
	}
}


int main()
{
	nineValley(9, 0, 500);
}