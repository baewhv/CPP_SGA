#include <iostream>
using namespace std;

// CODE
// 
// DATA
// �������� (��������)
// �����ֱ� : ���α׷� ���� �� �Ҵ�. ���α׷� ���� �� ����.
// ���� : ��𼭵� ������ �����ϴ�.
// ���� : ���� �� ���� ���� �Ұ���.
//       ������ ũ�Ⱑ �۴�.
// 
// STACK
// (��������, ��ȯ�ּҰ�, �Ű�����) => ����������
// ���� �ֱ� : �Լ� ȣ�� �� �Ҵ�. �Լ� ���� �� ����.
// ����, ���� : �Լ� ������ ���� �� ����.
// 
// HEAP
// ���α׷����� ����.
// �����ֱ� : ���α׷��Ӱ� ���� ����, �Ҹ��� ��������.
// C��Ÿ��
// malloc / free
// C++��Ÿ��
// new  / delete
// new[] / delete[] -> ���ϴ� �뷮 �Ҵ�.

//�����Ҵ�

class Player
{
public:
	Player() {}
	Player(int hp, int atk) : _hp(hp), _atk(atk) {}

	int _hp;
	int _atk;
};



int main()
{
	/* C��Ÿ�� �����Ҵ�
	//void* : Ÿ�� ���� ���𰡰� ������ �������� �� �� ����.
	void* ptr = malloc(100); //Heap ������ 100byte�� �Ҵ� �ް� �� ��ġ�� ����Ű�� ������ ��ȯ.
	int* intPtr = (int*)ptr;

	for (int i = 0; i < 25; i++)
	{
		*(intPtr + i) = i + 1;
	}

	free(ptr);
	*/ //C��Ÿ�� �����Ҵ�


	int* intPtr = new int();			//���� �����Ҵ�
	Player* pPtr = new Player(10, 2);	//Class �����Ҵ�
	char* charPtr = new char[100];


	Player* pArr = new Player[100];
	//stack���� �ּҰ��� 4byte�� ��Ƹ����� �� ������ �ѹ��� �ֱⰡ ��ƴ�.

	Player* pPtrArr[100] = { nullptr };
	
	for (int i = 0; i < 100; i++)
	{
		pPtrArr[i] = new Player();
	}


	int* tempPtr = (int*)charPtr;
	*tempPtr = 1;



	delete[] pArr;
	delete[] charPtr;
	delete intPtr;
	delete pPtr;


	return 0;
}