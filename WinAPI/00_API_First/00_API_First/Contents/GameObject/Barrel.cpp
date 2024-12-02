#include "framework.h"
#include "Barrel.h"
#include "Cannon.h"

Barrel::Barrel()
{
	_line = make_shared<Line>(Vector(), Vector());
}

Barrel::~Barrel()
{
}

void Barrel::Update()
{
	if (_cannon.expired())
		return;
	_line->_start = _cannon.lock()->GetCenter();
	_line->End() = _line->_start + ((mousePos - _line->_start).NormalVector() * 150);
	//_line->_end = _line->_start + _dir * _length;

	_line->Update();
}

void Barrel::Render(HDC hdc)
{
	_line->Render(hdc);
}
