#include "framework.h"
#include "FortressScene.h"

#include "Contents/GameObject/Fortress/Cannon.h"

FortressScene::FortressScene()
{
	_cannons.push_back(make_shared<Cannon>(Vector(WIN_WIDTH / 4, 350)));
	_cannons.push_back(make_shared<Cannon>(Vector(WIN_WIDTH / 4 * 3, 350)));
	_curCannon = _cannons[0];
	_nextCannon = _cannons[1];
	curCannonNum = 0;
	_cannons[curCannonNum]->SetTurn(true);
}

FortressScene::~FortressScene()
{
}

void FortressScene::Update()
{
	for (auto c : _cannons)
	{
		c->Update();
	}
 	CheckTurn();
}

void FortressScene::Render(HDC hdc)
{
	for (auto c : _cannons)
	{
		c->Render(hdc);
	}
}

void FortressScene::CheckTurn()
{
	if (_curCannon.expired())
	{
		ChoseTurn();
		return;
	}
	auto cCannon = _curCannon.lock();
	if (cCannon->GetTurn() == false && cCannon->ShootCount() == 0)
	{
		ChoseTurn();
	}
}

void FortressScene::ChoseTurn()
{
	_curCannon = _nextCannon;
	if (curCannonNum + 1 >= _cannons.size())
		curCannonNum = 0;
	else curCannonNum++;

	if (curCannonNum + 1 >= _cannons.size())
		_nextCannon = _cannons[0];
	else
		_nextCannon = _cannons[curCannonNum + 1];
	
	_curCannon.lock()->SetTurn(true);
}

void FortressScene::PostInitialize()
{
	for (auto c : _cannons)
	{
		c->PostInitialize();
	}
}
