#pragma once
class Barrel
{
public:
	Barrel();
	~Barrel();

	void Update();
	void Render(HDC hdc);

	void SetCannon(shared_ptr<class Cannon> cannon) { _cannon = cannon; }
	void SetDirection(Vector dir) { _dir = dir; }
	Vector& GetDirection() { return _dir; }
	float GetLength() { return _length; }
	
	Vector& GetMuzzle() { return _line->_end; }

private:
	shared_ptr<Line> _line;
	shared_ptr<RectangleCollider> _barrel;

	float _length = 150.0f; //-> 15f;
	float _thickness = 30.0f; // -> 57f;
	Vector _dir = Vector(1,0);

	//�ܺο��� ������ ���� ������ ���� weak_ptr�� ��ȯ������ ���´�.
	weak_ptr<class Cannon> _cannon;
};

