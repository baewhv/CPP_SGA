#include <iostream>

using namespace std;

//����
//����� ǥ���ϴ� 3����? const static?

//CODE

//DATA : ��������, ��������
//STACK : [��ȯ�ּҰ�][��������][�Ű�����] => ����������
//HEAP : ???

//aInt + bInt : aInt�� bInt�� ���� ������� �ӽ÷� ��ȯ.
//aInt - bInt : aInt�� bInt�� �� ������� �ӽ÷� ��ȯ.
//aInt * bInt : aInt�� bInt�� ���� ������� �ӽ÷� ��ȯ.
//float * float : �Ҽ����� ��.
// 
//aInt / bInt : aInt�� bInt�� ���� ����� �� ���� �ӽ÷� ��ȯ.
//aInt % bInt : aInt�� bInt�� ���� ����� �� �������� �ӽ÷� ��ȯ.
//float / float : 
// = : ���� ������
// += : ���� ������

// ���� ������ (int��������.)
//     ���� ������
//++aInt : a������ 1�� ���� ��ȯ�Ѵ�.
//     ���� ������
//aInt++ : �ش� �� ���� 1�� ���� ��ȯ�Ѵ�.

//�� ������ (��ȯ�� bool)
//<. <= , >, >=, ==, !=

//�� ������ (bool ���� ��)
// ! (���� / NOT) : true -> false / false -> true;
// 
// && (���� / AND) 
// || (���� / OR)

//��Ʈ ������ (��Ʈ�� ��)
// << , >> , &, |, ^
// << ���� ����Ʈ ����.
//    �ű� �� 0���� ä����.
//    unsinged ������ ���� ����.?
// >> ������ ����Ʈ ����.
//    �� ������ ��Ʈ�� ��������.
//    ��ȣ ��Ʈ�� �����ȴ�.
// &  ��Ʈ and ����.
//    ���� �ڸ��� ��Ʈ�� ���� 1�̸� 1, ������ 0
// |  ��Ʈ or ����.
//    ���� �ڸ��� ��Ʈ �� �ϳ��� 1�̸� 1.
// ^  ��Ʈ XOR ����. -> ��ȣ�ʿ��� ����?
//    ������ 0, �ٸ��� 1


unsigned char bitFlags;

unsigned char  stun =  0b0001;
unsigned char  airborne =  0b0010;
unsigned char  rooted = 0b0100;
unsigned char  slow = 0b1000;
int main()
{
	int aInt = 10;
	int bInt = 3;
	{
		
		int cInt = aInt % bInt;

		aInt %= 5;
		cout << (aInt = bInt) << endl;

		

	}
	char aChar = 'b';
	aChar++;

	aInt = 0;
	bInt = 3;

	aInt++;
	//���� ���� : 
	cout << ++aInt << endl;
	cout << aInt++ << endl;

	aInt = 3;
	bInt = 5;
	
	bool check1 = (aInt < bInt); // 3 < 5 true
	bool check2 = (aInt == bInt); // 3 != 5 false
	bool check3 = check1 < check2; // 1 < 0 false?

	bool check4 = (check1 && check3); // true && false = false;
	bool check5 = !check4 + 10;       // ture + 10 = true;
	bool check6 = check4 || check5 || check1 || check3 || check2; // true


	aInt = 3;
	bInt = 6;


	bitFlags = stun | slow;
	
	if (bitFlags & stun)
	{
		cout << "����" << endl;
	}

	bitFlags = bitFlags | !slow; //��ȭ? 1110
	bitFlags = bitFlags | rooted; //�ӹ�

	if (bitFlags & (stun | rooted))
	{
		cout << "���� / �ӹ�" << endl;
	}
	
	return 0;
}