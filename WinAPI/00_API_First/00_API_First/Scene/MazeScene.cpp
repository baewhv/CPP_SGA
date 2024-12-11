#include "framework.h"
#include "MazeScene.h"
#include "./Contents/GameObject/Maze/Maze.h"

MazeScene::MazeScene()
{
	_maze = make_shared<Maze>();

	//_maze->SetType(Block::BlockType::DISABLE);
}

MazeScene::~MazeScene()
{
}

void MazeScene::PostInitialize()
{
}

void MazeScene::Update()
{
	_maze->Update();
}

void MazeScene::Render(HDC hdc)
{
	_maze->Render(hdc);
}
