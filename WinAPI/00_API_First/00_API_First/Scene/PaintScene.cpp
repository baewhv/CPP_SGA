#include "framework.h"
#include "PaintScene.h"

PaintScene::PaintScene()
{
	_pens.reserve(3);
	{
		_pens.push_back(CreatePen(3, 3, RGB(255, 0, 0)));
		_pens.push_back(CreatePen(3, 3, RGB(0, 255, 0)));
		_pens.push_back(CreatePen(3, 3, RGB(0, 0, 255)));
	}

	_brushes.reserve(3);
	{
		_brushes.push_back(CreateSolidBrush(RGB(255,25,25)));
		_brushes.push_back(CreateSolidBrush(RGB(25,255,25)));
		_brushes.push_back(CreateSolidBrush(RGB(25,25,255)));
	}

	
}

PaintScene::~PaintScene()
{
	for (auto pen : _pens)
		DeleteObject(pen);
	for (auto brush : _brushes)
		DeleteObject(brush);
}

void PaintScene::Update()
{
	myCircle->Center() = mousePos;
	myBox->Center() = Lerp(myBox->Center(), mousePos, 0.1f);   //선형 보간
	myLine->End() = mousePos;
	myCircle->Update();
	myBox->Update();
	myLine->Update();
}

void PaintScene::Render(HDC hdc)
{
	SelectObject(hdc, _pens[0]);

	myCircle->Render(hdc);
	SelectObject(hdc, _pens[1]);

	myBox->Render(hdc);
	SelectObject(hdc, _pens[2]);
	myLine->Render(hdc);
}
