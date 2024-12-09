#include "framework.h"
#include "Program.h"

#include "Scene/PaintScene.h"
#include "Scene/CollisionScene.h"
#include "Scene/CannonScene.h"
#include "Scene/LineScene.h"
#include "Scene/FortressScene.h"

Program::Program()
{
    _sceneTable["PaintScene"] = make_shared<PaintScene>();
    _sceneTable["CollisionScene"] = make_shared<CollisionScene>();
    _sceneTable["CannonScene"] = make_shared<CannonScene>();
    _sceneTable["LineScene"] = make_shared<LineScene>();
    _sceneTable["FortressScene"] = make_shared<FortressScene>();

    _curScene = "FortressScene";

    _sceneTable[_curScene]->PostInitialize();
}

Program::~Program()
{
}

void Program::Update()
{
    _sceneTable[_curScene]->Update();
}

void Program::Render(HDC hdc)
{
    _sceneTable[_curScene]->Render(hdc);
}
