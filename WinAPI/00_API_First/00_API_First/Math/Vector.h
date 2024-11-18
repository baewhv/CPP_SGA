#pragma once
#include <math.h>

class Vector
{
public:
	Vector() : _x(0.0f), _y(0.0f) {}
	Vector(float x, float y) : _x(x), _y(y) { }

	Vector(const Vector& other) :_x(other._x), _y(other._y) {}
	~Vector() {}

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
	float Length() const
	{
		return sqrtf((_x * _x) + (_y * _y));  //피타고라스
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
		return Vector(_x - other._x, _y - other._y);
	}
	Vector operator*(const float& value) const
	{
		return Vector(_x * value, _y * value);
	}
	Vector NormalVector() const
	{
		return Vector(_x/Length(), _y/Length());
	}


public:
	float _x;
	float _y;
};