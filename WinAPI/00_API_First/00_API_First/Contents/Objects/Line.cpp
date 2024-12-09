#include "framework.h"
#include "Line.h"

Line::Line(Vector s, Vector e)
	:_start(s), _end(e)
{
	_colors[0] = CreatePen(3, 3, RED);
	_colors[1] = CreatePen(3, 3, GREEN);
}

Line::~Line()
{
	for (auto& pen : _colors)
	{
		DeleteObject(pen);
	}
}

void Line::Update()
{
}

void Line::Render(HDC hdc)
{
	SelectObject(hdc, _colors[_curColor]);

	MoveToEx(hdc, _start._x, _start._y, nullptr);
	LineTo(hdc, _end._x, _end._y);
}

Line::HitResult Line::IsCross(shared_ptr<Line>& other, Vector& x) const
{
	/*
	Vector a = _start;
	Vector b = _end;
	Vector c = other->_start;
	Vector d = other->_end;

	float crossed = (b - a).Cross(d - c);  //
	if (fabs(crossed) < FLT_EPSILON)  //두 선이 평행할 경우. 0나눌 우려가 있다.
		return false;
	x = a + (b - a) * ((c - a).Cross(d - c) / crossed);

	float ab = (b - a).Cross(c - a) * (b - a).Cross(d - a);
	float cd = (d - c).Cross(a - c) * (d - c).Cross(b - c);

	return  ab <=0 && cd <= 0;
	//이는 두 선분이 겹치는 식이라 방향과 관계가 없어져버렸다.
	*/

	Vector line1_s = _start;
	Vector line1_e = _end;
	Vector line2_s = other->_start;
	Vector line2_e = other->_end;

	Vector line1_sTos = line2_s - line1_s;
	Vector line1_sToe = line2_e - line1_s;

	Vector line2_sTos = line1_s - line2_s;
	Vector line2_sToe = line1_e - line2_s;
	
	bool isBetween1 = IsBetween((line1_e - line1_s), line1_sTos, line1_sToe);
	bool isBetween2 = IsBetween((line1_e - line1_s), line1_sTos, line1_sToe);

	float left = fabs((line2_e - line2_s).Cross(line1_s - line2_s));
	float right = fabs((line2_e - line2_s).Cross(line1_s - line2_s));

	float ratio = left / (left + right);

	Line::HitResult result;
	result._isHit = isBetween1 && isBetween2;
	result._pos = Lerp(line1_s, line1_e, ratio);


	return result;

}

bool Line::IsBetween(Vector center, Vector left, Vector right) const
{
	float Cross_s = center.Cross(left);
	float Cross_e = center.Cross(right);

	float result = Cross_s * Cross_e;

	return result < 0;
}

bool Line::IsInPoint(Vector& other) const
{
	float xc = other.Cross(_start);
	float xd = other.Cross(_end);
	if (xc * xd > 0)
		return false;
	return true;
}


