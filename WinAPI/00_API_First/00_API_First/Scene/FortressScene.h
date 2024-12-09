#pragma once
#include "Scene.h"
class Cannon;

class FortressScene :
	public Scene
{
public:
	FortressScene();
	~FortressScene();


	void PostInitialize() override;
	// Scene��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

private:
	shared_ptr<Cannon> _cannon1;
	shared_ptr<Cannon> _cannon2;
public:

	

	// Scene��(��) ���� ��ӵ�
	

};

