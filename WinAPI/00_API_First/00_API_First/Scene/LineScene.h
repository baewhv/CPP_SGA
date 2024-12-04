#pragma once
#include "Scene.h"
class LineScene : public Scene
{
public:
	LineScene();
	~LineScene();
	// Scene��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	shared_ptr<Line> _line1;
	shared_ptr<Line> _line2;
	shared_ptr<Line> _line3;

};

