#include <iostream>

using namespace std;

//연산자 오버로딩
// => 다형성

class Vector
{
public:
	Vector() : _x(0.0f), _y(0.0f) {}
	Vector(float x, float y) : _x(x), _y(y) {}

	//복사생성자
	//암시적으로 만들어주는 생성자.
	Vector(const Vector& other)
		:_x(other._x)
		,_y(other._y)
	{

	}


	~Vector() {}

	void PrintVector()
	{
		cout << "X : " << _x << endl;
		cout << "Y : " << _y << endl;
	}

	//덧셈연산자
	//a + b : a 와 b를 더하고 그 값을 변환한다.
	Vector operator+(const Vector& other) const
		//& -> 값전달의 경우 용량이 클 수록 복사할 양도 많아짐. 그래서 주소복사로 전달.
		//const -> 주소복사를 통해 원본 훼손을 방지.
		//const(뒤) -> this를 사용할 수 있는데 이 또한 원본 참조가 가능하므로 읽기전용화 하여 훼손을 방지.
	{
		Vector result;
		result._x = this->_x + other._x;
		result._y = this->_y + other._y;

		//this : 이 함수를 호출한 객체 자신 포인터.
		return result;
	}

	//뺄셈 연산자 오버로딩
	//곱셈 연산자 오버로딩
	//백터 내적 연산 함수.
	//	-> Dot
	//백터 외적 연산 함수.
	//	-> Cross
	//  -> 두 백터가 있을 때 외적
	//  -> 외적은 두 벡터의 수직인 값. 그러나 2차원에서의 수직은 

	// 복사 대입 연산자 : 
	// a = b -> a에 b를 대입하고 a의 원본을 반환한다.
	Vector& operator=(const Vector& other)
	{
		_x = other._x;
		_y = other._y;

		return *this;
	}

	// 임의 접근 연산자 오버로딩.
	float& operator[](int temp)
	{
		if (temp == 0)
			return _x;
		else
			return _y;
	}


public:
	float _x;
	float _y;
};


int main()
{
	Vector v1 = Vector(1, 1);
	Vector v2 = Vector(2, 3);

	Vector v3 = v1 + v2;
	Vector v4 = v1.operator+(v2);
}