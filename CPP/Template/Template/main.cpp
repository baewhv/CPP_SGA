#include <iostream>

using namespace std;



//�Լ��� Ŭ���� �տ� ���ø��� �ٿ� ���.
//Ŭ���� ��� �� ���ø��� �����ͷ� �����صΰų� �Լ��� ���.
// 
//�Լ� ��� �� ���ø��� �Ű������� 
//�Լ� �����ε��� ���� ������ �̸��� �Լ��� �Ź� �����ϴ� ������ �ٿ�
//���ø��� �̿��� �����Ϸ����� ������ �߷��ϰ���.


template <class T1, int I> 
T1 testFunction(T1* lhs, T1* rhs)
{
	return lhs - rhs + I;
};

template <typename T>
class TestTemplate {
public:
	TestTemplate(T temp) { _temp1 = temp; }
	T _temp1;
};


class Aclass
{
public:
	int b;

	Aclass() : b(5) {}
	Aclass(int a) : b(a) {}

	Aclass* operator-(Aclass* b)
	{
		
		return new Aclass(this->b - b->b);
	}
};

template <typename T>
class TestClass {
public:
	T testF(T lhs, T rhs)
	{
		return lhs + rhs;
	}
};

int main()
{
	Aclass* a1 = new Aclass(5);
	Aclass* b1 = new Aclass(3);

	Aclass c1 = testFunction<Aclass, 10>(a1, b1);

	int c2 = testFunction(5, 3);


	TestTemplate* iTemp = new TestTemplate(c2);

	TestClass<Aclass>* t = new TestClass<Aclass>;

	return 0;
}