#include "framework.h"
#include "Block.h"

Block::Block()
{
	_rect = make_shared<RectCollider>(Vector(300, 300), Vector(15, 15));
	_rect->SetBlack();

	_brushes.push_back(CreateSolidBrush(WHITE));
	_brushes.push_back(CreateSolidBrush(ROADGREEN));
	_brushes.push_back(CreateSolidBrush(REDWALL));
	_brushes.push_back(CreateSolidBrush(SAND_DOLLOR));
	_brushes.push_back(CreateSolidBrush(GRAY));
	_brushes.push_back(CreateSolidBrush(RGB(220, 25, 220)));
	_brushes.push_back(CreateSolidBrush(RGB(220, 25, 220)));
	_brushes.push_back(CreateSolidBrush(WHITE));
	_brushes.push_back(CreateSolidBrush(BLACK));
}

Block::~Block()
{
	for (int i = 0; i < _brushes.size(); i++)
	{
		DeleteObject(_brushes[i]);
	}
}

void Block::Update()
{
	_rect->Update();
}

void Block::Render(HDC hdc)
{
	SelectObject(hdc, _brushes[static_cast<unsigned int>(_curType)]);
	_rect->Render(hdc);
}
