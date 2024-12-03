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
	float Length() const                        //��Ÿ����� ���Ǹ� �̿��� ���̸� ���
	{
		return sqrtf((_x * _x) + (_y * _y));  //��Ÿ���
	}

	Vector operator+(const Vector& other) const  //���� �� - ��ġ���� -> �� ���͸� ��ģ ��ġ�� ǥ��
	{
		Vector result;
		result._x = this->_x + other._x;
		result._y = this->_y + other._y;
		return result;
	}
	Vector operator-(const Vector& other) const //���� �� - �Ÿ� ���(�ϳ��� �������� �ΰ� ���Ͱ� �Ÿ��� ����� �� �ִ�.
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