#include <iostream>

using namespace std;

//�Լ� ����������
//�Լ��� : �Կ��ٰ� � ���� �ְ�(input) � ���� ��ȯ�޴� ��(output)
//��ȯ����, �Ű������� �ڷ���, ����, �Լ� �̸� => �Լ� �ñ״���
int Add(int a, int b);	//�Լ� ���� => �Լ� �ñ״���.
float Add(float a, float b); //�Լ� �����ε� : ������ ��Ī�� �Լ��� �ٸ� ��ȯ���� �Ű������� ����.
//int Add(int a, int b, int c = 1); // =1 -> �Լ��� �⺻ ����. �� ������ ���ʴ�� ���� ����. ������ �Ű����� 2��¥���� ������ ��ȣ����.
int Add(int a, int b, int c);
int Add(int a, int b, int c, int d, int e = 1); //

int Add(int a, int b);


void HelloWorld(void)	//void
{
	cout << "Hello World" << endl;
	return;
}

int Factorial(int n)	//����Լ�. �ʹ� ���� ���� ������ Stack overflow
{
	if (n == 1)
		return 1;
	return n * Factorial(n - 1);
}


int main()
{
	//���� ����
	//�õ� �ɱ�
	srand(time(NULL));
	//���� ����.
	int randNum = rand();

	int answer = 0;

	cin >> answer;


	//main [��ȯ�ּҰ�, ��������(aInt), �Ű�����(void)]
	int aInt = Add(5, 3);
	int aInt5 = Add(1, 2, 3, 4, 1);
	int factorial = Factorial(51);

	cout << aInt << endl;
	return 0;
}

int Add(int a, int b)	//�Լ� ����
{
	//Add [��ȯ�ּҰ�, ��������(cInt = �����Ⱚ), �Ű�����(a = 5, b = 3)]
	//main [��ȯ�ּҰ�, ��������(aInt), �Ű�����(void)]
	int cInt = a + b;

	//Add [��ȯ�ּҰ�, ��������(cInt = 8), �Ű�����(a = 5, b = 3)]
	//main [��ȯ�ּҰ�, ��������(aInt), �Ű�����(void)]
	return cInt; //��ȯ���� cInt ����.
}

float Add(float a, float b)
{
	float cFloat = a + b;

	return cFloat;
}

int Add(int a, int b, int c)
{
	int dInt = a + b + c;
	return dInt;
}

int Add(int a, int b, int c, int d, int e)
{
	int answer = Add(a, b, c) + Add(d, e);
	return answer;
}

//���� 1.
//���������� �����.

//���� 2.
//������ �����.





