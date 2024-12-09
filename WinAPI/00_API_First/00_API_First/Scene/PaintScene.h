#pragma once
#include "Scene.h"
class PaintScene : public Scene //ctrl+. ���� �����Լ� ����
{
public:
	PaintScene();
	~PaintScene();

	// Scene��(��) ���� ��ӵ�
	virtual void PostInitialize() override;
	void Update() override;
	void Render(HDC hdc) override;

private:
	int _curColor = 0;

	vector<HPEN> _pens;
	vector<HBRUSH> _brushes;

	shared_ptr<CircleCollider> myCircle = make_shared<CircleCollider>(Vector(200, 200), 50);
	shared_ptr<RectCollider> myBox = make_shared<RectCollider>(Vector(100, 100), Vector(100, 200));
	shared_ptr<Line> myLine = make_shared<Line>(Vector(150, 150), Vector(300, 300));
};

