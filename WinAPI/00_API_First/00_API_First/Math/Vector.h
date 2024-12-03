#pragma once
#include <math.h>

class Vector
{
public:
	Vector() : _x(0.0f), _y(0.0f) {}
	Vector(float x, float y) : _x(x), _y(y) { }

	Vector(const Vector& other) :_x(other._x), _y(other._y) {}
	~Vector() {}

	float Dot(const Vector& other) const
	{
		float result;
		result = (this->_x * other._x) + (this->_y * other._y);
		
		return result;
	}
	float Cross(const Vector& other)const
	{
		float result;
		result = this->_x * other._y - this->_y * other._x;
		return result;
	}
	float Length() const                        //피타고라스의 정의를 이용해 길이를 계산
	{
		return sqrtf((_x * _x) + (_y * _y));  //피타고라스
	}

	Vector operator+(const Vector& other) const  //벡터 합 - 위치벡터 -> 두 벡터를 합친 위치를 표기
	{
		Vector result;
		result._x = this->_x + other._x;
		result._y = this->_y + other._y;
		return result;
	}
	Vector operator-(const Vector& other) const //벡터 차 - 거리 계산(하나를 기준으로 두고 벡터간 거리를 계산할 수 있다.
	{
		return Vector(_x - other._x, _y - other._y);
	}
	Vector operator*(const float& value) const
	{
		return Vector(_x * value, _y * value);
	}

	Vector& operator=(const Vector& other)
	{
		_x = other._x;
		_y = other._y;
		return *this;
	}
	Vector& operator+=(const Vector& other)
	{
		_x += other._x;
		_y += other._y;
		return *this;
	}
	Vector& operator-=(const Vector& other)
	{
		_x -= other._x;
		_y -= other._y;
		return *this;
	}

	Vector NormalVector() const
	{
		float length = Length();

		return Vector(_x / length, _y / length);
	}

	void Normalize()
	{
		float length = Length();

		_x /= length;
		_y /= length;
	}

public:
	float _x;
	float _y;
};