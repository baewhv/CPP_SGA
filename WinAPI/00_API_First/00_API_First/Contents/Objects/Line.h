#pragma once
class Line
{
public:
	Line(Vector s, Vector e);
	~Line();

	void Update();
	void Render(HDC hdc);

private:
	Vector _start;
	Vector _end;

};

