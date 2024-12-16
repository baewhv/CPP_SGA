#include "framework.h"
#include "Program.h"

#include "Scene/PaintScene.h"
#include "Scene/CollisionScene.h"
#include "Scene/CannonScene.h"
#include "Scene/LineScene.h"
#include "Scene/FortressScene.h"
#include "Scene/MazeScene.h"

HDC Program::backBuffer = nullptr;

Program::Program()
{
    srand(time(nullptr));
    HDC hdc = GetDC(hWnd);

    backBuffer = CreateCompatibleDC(hdc);
    _hBitMap = CreateCompatibleBitmap(hdc, WIN_WIDTH, WIN_HEIGHT); //도화지
    //여기다 그려라?
    SelectObject(backBuffer, _hBitMap);


    _sceneTable["PaintScene"] = make_shared<PaintScene>();
    _sceneTable["CollisionScene"] = make_shared<CollisionScene>();
    _sceneTable["CannonScene"] = make_shared<CannonScene>();
    _sceneTable["LineScene"] = make_shared<LineScene>();
    _sceneTable["FortressScene"] = make_shared<FortressScene>();
    _sceneTable["MazeScene"] = make_shared<MazeScene>();

    _curScene = "MazeScene";

    _sceneTable[_curScene]->PostInitialize();
}

Program::~Program()
{
    DeleteObject(backBuffer);
    DeleteObject(_hBitMap);
}

void Program::Update()
{
    _sceneTable[_curScene]->Update();
}

void Program::Render(HDC hdc)
{
    PatBlt(backBuffer, 0, 0, WIN_WIDTH, WIN_HEIGHT, BLACKNESS);
    //그림을 그림.
    _sceneTable[_curScene]->Render(backBuffer);
    //복사
    BitBlt(
        hdc,
        0, 0,
        WIN_WIDTH, WIN_HEIGHT,
        backBuffer,
        0,
        0,
        SRCCOPY
    );
}
