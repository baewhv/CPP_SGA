#pragma once
#include "Scene.h"
class LineScene : public Scene
{
public:
	LineScene();
	~LineScene();
	// Scene��(��) ���� ��ӵ�
	virtual void PostInitialize() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	shared_ptr<Line> _line1;
	shared_ptr<Line> _line2;
	shared_ptr<Line> _line3;

	shared_ptr<Line> _subLine1;
	shared_ptr<CircleCollider> _crossPoint;


	// Scene��(��) ���� ��ӵ�

};
