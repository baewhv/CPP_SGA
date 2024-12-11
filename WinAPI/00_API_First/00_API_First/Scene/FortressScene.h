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
	vector<shared_ptr<Cannon>> _cannons;
	int curCannonNum;

	weak_ptr<Cannon> _curCannon;
	weak_ptr<Cannon> _nextCannon;
	
	void CheckTurn();
	void ChoseTurn();
};

