#include <iostream>

using namespace std;



//함수나 클래스 앞에 템플릿을 붙여 사용.
//클래스 사용 시 템플릿을 포인터로 저장해두거나 함수에 사용.
// 
//함수 사용 시 템플릿을 매개변수와 
//함수 오버로딩을 통해 동일한 이름의 함수를 매번 찍어내야하는 과정을 줄여
//템플릿을 이용해 컴파일러에서 형식을 추론하게함.


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