#include <iostream>

using namespace std;

int main()
{
	const int a = 5;
	const int* ca = &a;
	//*ca += 5; //������ �� ���� ��.

	int* cb = const_cast<int*>(ca);
	*cb += 5;
	cout << *cb << endl;
	cout << a << endl;  //����� �󿡼��� 10�ε� ����� �� 5�ϱ�?
	cout << a << endl;  //�����Ϸ� ����ȭ ���� ����
	cout << *ca << a << endl;
	return 0;
}