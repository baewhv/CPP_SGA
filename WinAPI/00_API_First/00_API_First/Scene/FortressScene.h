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
	// Scene을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render(HDC hdc) override;

	//void NextTurn() { _myTurn = !_myTurn; }

private:
	vector<shared_ptr<Cannon>> _cannons;
	vector<shared_ptr<RectCollider>> _hpBar;
	int curCannonNum;

	weak_ptr<Cannon> _curCannon;
	weak_ptr<Cannon> _nextCannon;

	void CheckTurn();
	void ChoseTurn();

	//bool _myTurn = false;
};

