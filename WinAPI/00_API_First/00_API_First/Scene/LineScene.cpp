#include "framework.h"
#include "LineScene.h"

LineScene::LineScene()
{
	_line1 = make_shared<Line>(Vector(100, 100), Vector(0, 0));
	_line2 = make_shared<Line>(Vector(0, 500), Vector(1280, 500));
	_line3 = make_shared<Line>(Vector(100, 400), Vector(150, 400));
	_subLine1 = make_shared<Line>(Vector(100,400), Vector(800, 100));
	_crossPoint = make_shared<CircleCollider>(Vector(WIN_WIDTH/2,WIN_HEIGHT/2), 5.0f);
}

LineScene::~LineScene()
{
}

void LineScene::Update()
{
	_line1->_end = mousePos;
	Vector line2Nor = (_line2->_end - _line2->_start).NormalVector(); //기준선의 노말 벡터
	Vector line1v = _line1->_end - _line1->_start;

	//float length = line2Nor.Dot(line1v); //목표선을 기준선에 내적.
	float ang = line1v.Angle(line2Nor);
	float length = line1v.Length() * cos(ang);
	_line3->_end = _line3->_start + (line2Nor * length);
	

	bool crossed = _line1->IsCross(_subLine1, _crossPoint->Center());

	if (crossed == true)
	{
		_subLine1->SetRed();
		_crossPoint->SetVisible(true);
	}
	else
	{
		_subLine1->SetGreen();
		_crossPoint->SetVisible(false);
	}


	_line1->Update();
	//_line2->Update();
	//_line3->Update();
	_subLine1->Update();
	_crossPoint->Update();
}

void LineScene::Render(HDC hdc)
{
	_line1->Render(hdc);
	//_line2->Render(hdc);
	//_line3->Render(hdc);
	_subLine1->Render(hdc);
	_crossPoint->Render(hdc);
}
