#include <iostream>
using namespace std;

class Vector
{
public:
	Vector() : _x(0.0f), _y(0.0f) {}
	Vector(float x, float y) : _x(x), _y(y) { }

	Vector(const Vector& other) :_x(other._x), _y(other._y) {}
	~Vector() {}

	void PrintVector()
	{
		cout << "x : " << _x << endl;
		cout << "y : " << _y << endl;
	}


	Vector operator+(const Vector& other) const
	{
		Vector result;
		result._x = this->_x + other._x;
		result._y = this->_y + other._y;
		return result;
	}
	Vector operator-(const Vector& other) const
	{
		Vector result;
		result._x = this->_x - other._x;
		result._y = this->_y - other._y;
		return result;
	}

	//벡터간의 직접적인 곱은 없고 내적과 외적이 있다.
	//실수를 곱하여 Scale값 조절한다.
	Vector operator*(const float value) const
	{
		Vector result;
		result._x = this->_x * value;
		result._y = this->_y * value;
		return result;
	}

	Vector Dot(const Vector& other) const
	{
		Vector result;
		result._x = this->_x * other._x;
		result._y = this->_y * other._y;
		return result;
	}

	float Cross(const Vector& other)const
	{
		float result;
		result = this->_x * other._y - this->_y * other._x;
		return result;
	}

	float Length()
	{
		return sqrtf((_x * _x) + (_y * _y));  //피타고라스
	}

	Vector NormalVector()
	{
		Vector result;
		result._x = this->_x * (1 / Length());
		result._y = this->_y * (1 / Length());

		return result;
	}

public:
	float _x;
	float _y;

};


int main()
{
	Vector v1 = Vector(5, 0);
	Vector v2 = Vector(0, 6);

	cout << "Vector A" << endl;
	v1.PrintVector();

	cout << endl;
	cout << "Vector B" << endl;
	v2.PrintVector();

	cout << endl;
	Vector v3;
	v3 = v1.Dot(v2);
	cout << "Dot Product(Vecotr)" << endl;
	v3.PrintVector();

	cout << endl;
	cout << "Dot Product(Scalar)" << endl;
	cout << v3._x + v3._y << endl;

	cout << endl;
	cout << "Cross Product : " << v1.Cross(v2)<<  endl;

}