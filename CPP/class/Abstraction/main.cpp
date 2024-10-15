#include <iostream>

using namespace std;

//�������̽���
//UI : User Interface;
//���� �����͸� ������ �� �ִ� ����(�б�, ����)

//�߻�ȭ
//1. ��üȭ �� �� ����.
//2. ���������Լ��� �ϳ� �̻� ���ԵǸ� �߻� Ŭ������.
//3. �߻�Ŭ������ �ڽ��� ��üȭ ��Ű���� ���������Լ��� �����ؾ� �Ѵ�.

class Bank
{
public:
	virtual void PrintInfo() abstract; //���������Լ�

	/*virtual void PrintInfo()
	{
		cout << _money << endl;
		cout << "�����Դϴ�." << endl;
	}*/
	void AddMoney(int value)
	{
		_money += value;
	}

protected:
	int _money;
};

class Kakao : public Bank
{
	virtual void PrintInfo() override //���� ���� �Լ� �������̵�
		//�������̽� ����
		//C++���� : protected ��������� ������ �� �ִ� ������ �����϶�.
	{
		cout << "īī����ũ �Դϴ�." << endl;
		cout << "�����Ͻ� �ݾ��� : " << _money << endl;

	}
};

class Shinhan : public Bank
{

};


class Player
{

};

int main()
{
	//Bank* b = new Bank();	//���� ���� �Լ��� �־� ������ �Ұ�.
	Bank* k = new Kakao();

	k->AddMoney(100);
	k->PrintInfo();

	return 0;
}