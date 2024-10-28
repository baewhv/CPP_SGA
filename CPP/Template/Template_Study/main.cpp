#include <iostream>

using namespace std;


// Template(����Ʋ)
// - �Լ� ���ø�
// -> �Լ��� ����.
// �����Ϸ��� �Լ��� ������.

//         class�� ��ü ����.
template <typename T = int>  //���ø� �⺻����
T Add(T a, T b)
{
	return a + b;
}

template <> //���ø� Ư��ȭ
double Add(double a, double b)
{
	cout << a << " + " << b << endl;
	return a + b;
}

template <typename F>
void ExecuteF(F func)
{
	func();
}

void HelloWorld()
{
	cout << "Hello Template" << endl;
}

struct Hello
{
	void operator()()
	{
		cout << "Hello Template Functor" << endl;
	}
};

typedef void(*FN)(void);


// Ŭ���� ���ø�
// -> ���赵�� ����.



//���� ���� �Ӽ��� T�� �Ѵ�.
template <typename T = float>
struct Vector2
{
	T DotProduct(const Vector2<T>& other)
	{
		return x * other.x + y * other.y;
	}

	T x;
	T y;
};

template<>
struct Vector2<double>
{
	double DotProduct(const Vector2<double>& other)
	{
		cout << "���ø� Ư��ȭ : double" << endl;
		return x * other.x + y * other.y;
	}
	double x;
	double y;
};

int main()
{
	int aInt = Add(1, 2);
	//static_cast
	float bFloat = Add<float>(1.1f, 2.1f);
	double aDouble = Add<double>(2.5, 2.3);



	ExecuteF<FN>(&HelloWorld);

	Hello hi;
	ExecuteF<Hello>(hi);

	//ExecuteF<FN>(&Add);

	Vector2<int> v = { 1,2 };
	Vector2<> v2 = { 1.1f,2.2f };

}