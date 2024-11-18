#include "framework.h"
#include "Line.h"

Line::Line(Vector s, Vector e)
	:_start(s), _end(e)
{
}

Line::~Line()
{
}

void Line::Update()
{
}

void Line::Render(HDC hdc)
{
	MoveToEx(hdc, _start._x, _start._y, nullptr);
	LineTo(hdc, _end._x, _end._y);
}
