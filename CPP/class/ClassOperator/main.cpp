#include <iostream>

using namespace std;

//������ �����ε�
// => ������

class Vector
{
public:
	Vector() : _x(0.0f), _y(0.0f) {}
	Vector(float x, float y) : _x(x), _y(y) {}

	//���������
	//�Ͻ������� ������ִ� ������.
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

	//����������
	//a + b : a �� b�� ���ϰ� �� ���� ��ȯ�Ѵ�.
	Vector operator+(const Vector& other) const
		//& -> �������� ��� �뷮�� Ŭ ���� ������ �絵 ������. �׷��� �ּҺ���� ����.
		//const -> �ּҺ��縦 ���� ���� �Ѽ��� ����.
		//const(��) -> this�� ����� �� �ִµ� �� ���� ���� ������ �����ϹǷ� �б�����ȭ �Ͽ� �Ѽ��� ����.
	{
		Vector result;
		result._x = this->_x + other._x;
		result._y = this->_y + other._y;

		//this : �� �Լ��� ȣ���� ��ü �ڽ� ������.
		return result;
	}

	//���� ������ �����ε�
	//���� ������ �����ε�
	//���� ���� ���� �Լ�.
	//	-> Dot
	//���� ���� ���� �Լ�.
	//	-> Cross
	//  -> �� ���Ͱ� ���� �� ����
	//  -> ������ �� ������ ������ ��. �׷��� 2���������� ������ 

	// ���� ���� ������ : 
	// a = b -> a�� b�� �����ϰ� a�� ������ ��ȯ�Ѵ�.
	Vector& operator=(const Vector& other)
	{
		_x = other._x;
		_y = other._y;

		return *this;
	}

	// ���� ���� ������ �����ε�.
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