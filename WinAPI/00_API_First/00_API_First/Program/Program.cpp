#include "framework.h"
#include "Program.h"

#include "Scene/PaintScene.h"
#include "Scene/CollisionScene.h"

Program::Program()
{
    _sceneTable["PaintScene"] = make_shared<PaintScene>();
    _sceneTable["CollisionScene"] = make_shared<CollisionScene>();

    _curScene = "CollisionScene";
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
