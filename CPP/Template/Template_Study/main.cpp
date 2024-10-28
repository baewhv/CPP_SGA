#include <iostream>

using namespace std;


// Template(주조틀)
// - 함수 템플릿
// -> 함수를 찍어낸다.
// 컴파일러가 함수를 만들어낸다.

//         class로 대체 가능.
template <typename T = int>  //템플릿 기본인자
T Add(T a, T b)
{
	return a + b;
}

template <> //템플릿 특수화
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


// 클래스 템플릿
// -> 설계도를 찍어낸다.



//보통 내부 속성을 T로 한다.
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
		cout << "템플릿 특수화 : double" << endl;
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