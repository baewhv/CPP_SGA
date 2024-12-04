#include "framework.h"
#include "Barrel.h"
#include "Cannon.h"

Barrel::Barrel()
{
	_line = make_shared<Line>(Vector(), Vector());
	_barrel = make_shared<RectangleCollider>(Vector(), Vector(_length, 30), 0.0f);
	
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

	_barrel->Center() = _cannon.lock()->GetCenter() + _dir * (_length / 2.0f);
	_barrel->Direction() = _dir;
}

void Barrel::Render(HDC hdc)
{
	_line->Render(hdc);
	_barrel->Render(hdc);
}
