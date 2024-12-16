#pragma once
struct MazeVector
{
	MazeVector() = default;
	MazeVector(int y, int x) : y(y), x(x) {}

	MazeVector operator+(const MazeVector& other) const  //���� �� - ��ġ���� -> �� ���͸� ��ģ ��ġ�� ǥ��
	{
		MazeVector result;
		result.y = this->y + other.y;
		result.x = this->x + other.x;
		return result;
	}
	MazeVector operator-(const MazeVector& other) const //���� �� - �Ÿ� ���(�ϳ��� �������� �ΰ� ���Ͱ� �Ÿ��� ����� �� �ִ�.
	{
		return MazeVector(y - other.y, x - other.x);
	}
	MazeVector operator*(const float& value) const
	{
		return MazeVector(y * value, x * value);
	}

	MazeVector& operator=(const MazeVector& other)
	{
		y = other.y;
		x = other.x;
		return *this;
	}
	MazeVector& operator+=(const MazeVector& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}
	MazeVector& operator-=(const MazeVector& other)
	{
		y -= other.y;
		x -= other.x;
		return *this;
	}
	int y = 0; //�� row
	int x = 0; //�� column
};

