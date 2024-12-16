#include "framework.h"
#include "MazeScene.h"
#include "Contents/GameObject/Maze/Maze.h"
#include "Contents/GameObject/Maze/MazePlayer.h"

MazeScene::MazeScene()
{
	_maze = make_shared<Maze>();
	_player = make_shared<MazePlayer>();
	//_maze->SetType(Block::BlockType::DISABLE);

	
}

MazeScene::~MazeScene()
{
}

void MazeScene::PostInitialize()
{
	_player->SetMaze(_maze);
	_player->Init();
}

void MazeScene::Update()
{
	_maze->Update();
	_player->Update();
}

void MazeScene::Render(HDC hdc)
{
	_maze->Render(hdc);
}
