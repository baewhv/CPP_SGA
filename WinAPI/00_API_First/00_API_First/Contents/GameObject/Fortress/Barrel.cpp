#include "framework.h"
#include "Barrel.h"
#include "Cannon.h"

Barrel::Barrel()
{
	_line = make_shared<Line>(Vector(), Vector());
	_barrel = make_shared<RectangleCollider>(Vector(), Vector(_length, _thickness), 0.0f);
	
}

Barrel::~Barrel()
{
}

void Barrel::Update()
{
	_line->Update();
	_barrel->Update();

	if (_cannon.expired())
		return;

	_line->_start = _cannon.lock()->GetCenter();
	_line->_end = _line->_start + _dir * _length;

	_barrel->SetSize(Vector(_length - (_length * _cannon.lock()->GetBarrelRatio() * 0.6f),
							_thickness + (_thickness * _cannon.lock()->GetBarrelRatio() * 0.45f)));
	_barrel->Center() = _cannon.lock()->GetCenter() + _dir * ((_length * 0.5f) - (_length * _cannon.lock()->GetBarrelRatio() * 0.3f));
	//캐논의 중심에서 + 방향 * 길이의 0.5?
	_barrel->Direction() = _dir;
}

void Barrel::Render(HDC hdc)
{
	_line->Render(hdc);
	_barrel->Render(hdc);
}
