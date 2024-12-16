#include "framework.h"
#include "Maze.h"
#include "Block.h"

Maze::Maze()
{
	Vector offset = Vector(300, 100);

	_blocks.resize(25);
	for (int y = 0; y < MAX_Y; y++)
	{
		_blocks[y].reserve(25);
		for (int x = 0; x < MAX_X; x++)
		{
			shared_ptr<Block> block = make_shared<Block>();
			Vector pos;
			pos._y = y * 18;
			pos._x = x * 18;
			block->SetPos(pos + offset);
			block->SetType(Block::ABLE);

			_blocks[y].push_back(block);
		}
	}
	CreateMaze();
}

Maze::~Maze()
{
}

void Maze::Update()
{
	for (auto blocks : _blocks)
	{
		for (auto block : blocks)
		{
			block->Update();
		}
	}
}

void Maze::Render(HDC hdc)
{
	for (auto blocks : _blocks)
	{
		for (auto block : blocks)
		{
			block->Render(hdc);
		}
	}
}

void Maze::CreateMaze()
{
	for (int y = 0; y < MAX_Y; y++)
	{
		for (int x = 0; x < MAX_X; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
			{
				_blocks[y][x]->SetType(Block::BlockType::DISABLE);
			}
		}
	}

	for (int y = 0; y < MAX_Y; y++)
	{
		for (int x = 0; x < MAX_X; x++)
		{
			if ((x == 1 && y == 1))
				_blocks[y][x]->SetType(Block::BlockType::ABLE);
			if (x == MAX_X - 2 && y == MAX_Y - 2)
			{
				_blocks[y][x]->SetType(Block::BlockType::ABLE);
				continue;
			}
			if (x % 2 == 0 || y % 2 == 0) continue;
			if (x == MAX_X - 2)
			{
				_blocks[y + 1][x]->SetType(Block::BlockType::ABLE);
				continue;
			}
			if (y == MAX_Y - 2)
			{
				_blocks[y][x+1]->SetType(Block::BlockType::ABLE);
				continue;
			}
			int randValue = rand() % 2;
			if (randValue == 0) //¿À¸¥ÂÊ ¶Õ±â
				_blocks[y][x+1]->SetType(Block::BlockType::ABLE);
			else //¾Æ·¡ ¶Õ±â.
				_blocks[y+1][x]->SetType(Block::BlockType::ABLE);
		}
	}
}
