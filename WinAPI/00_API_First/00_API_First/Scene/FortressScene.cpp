#include "framework.h"
#include "FortressScene.h"

#include "Contents/GameObject/Cannon.h"

FortressScene::FortressScene()
{
	_cannon1 = make_shared<Cannon>(Vector(WIN_WIDTH/4, 350));
	_cannon2 = make_shared<Cannon>(Vector(WIN_WIDTH / 4 * 3, 350));
}

FortressScene::~FortressScene()
{
}

void FortressScene::Update()
{
	_cannon1->Update();
	_cannon2->Update();

}

void FortressScene::Render(HDC hdc)
{
	_cannon1->Render(hdc);
	_cannon2->Render(hdc);
}

void FortressScene::PostInitialize()
{
	_cannon1->PostInitialize();
	_cannon2->PostInitialize();
}
