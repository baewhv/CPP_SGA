#pragma once
class Line
{
public:
	Line(Vector s, Vector e);
	~Line();


	void Update();
	void Render(HDC hdc);

	void SetRed() { _curColor = 0; }
	void SetGreen() { _curColor = 1; }

public:
	Vector _start;
	Vector _end;
	int _curColor = 1;
	HPEN _colors[2];

};

