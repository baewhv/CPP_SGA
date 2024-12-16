#pragma once
struct MazeVector
{
	MazeVector() = default;
	MazeVector(int y, int x) : y(y), x(x) {}

	MazeVector operator+(const MazeVector& other) const  //벡터 합 - 위치벡터 -> 두 벡터를 합친 위치를 표기
	{
		MazeVector result;
		result.y = this->y + other.y;
		result.x = this->x + other.x;
		return result;
	}
	MazeVector operator-(const MazeVector& other) const //벡터 차 - 거리 계산(하나를 기준으로 두고 벡터간 거리를 계산할 수 있다.
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
	int y = 0; //열 row
	int x = 0; //행 column
};

