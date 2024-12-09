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
