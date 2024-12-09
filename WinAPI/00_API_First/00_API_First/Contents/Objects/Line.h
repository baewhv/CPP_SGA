#pragma once
class Line
{
public:
	struct HitResult
	{
		bool _isHit;
		Vector _pos;
	};

	Line(Vector s, Vector e);
	~Line();

	void Update();
	void Render(HDC hdc);

	void SetRed() { _curColor = 0; }
	void SetGreen() { _curColor = 1; }

	HitResult IsCross(shared_ptr<Line>& other, Vector& x) const;
	bool IsInPoint(Vector& other) const;

	bool IsBetween(Vector center, Vector left, Vector right) const;

public:
	Vector _start;
	Vector _end;
	int _curColor = 1;
	HPEN _colors[2];


};

