#pragma once
#include "Barrel.h"

class Cannon : public enable_shared_from_this<Cannon>
{
public:
	Cannon();
	~Cannon();

	void Update();
	void Render(HDC hdc);

	float& Angle(float& angle) {return _angle; }
	const Vector& GetCenter() { return _body->Center(); }

	void Ready() { _barrel->SetCannon(shared_from_this()); }
private:
	// �Է����� �¿�� �����̰� ����� �Լ�
	void InputMove();
	// �Է����� �ѽ��� ������ +,-�� �ǰ� ����� �Լ�
	void InputBarrelRotation();

	

private:
	shared_ptr<CircleCollider> _body;
	//shared_ptr<Line> _barrel;
	shared_ptr<class Barrel> _barrel;
	float _angle = 0.0f;
};