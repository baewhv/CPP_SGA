#include "framework.h"
#include "CannonScene.h"

#include "Contents/GameObject/Cannon.h"

CannonScene::CannonScene()
{
	_cannon = make_shared<Cannon>();

	_cannon->Ready();
}

CannonScene::~CannonScene()
{
}

void CannonScene::Update()
{
	_cannon->Update();
}

void CannonScene::Render(HDC hdc)
{
	_cannon->Render(hdc);
}