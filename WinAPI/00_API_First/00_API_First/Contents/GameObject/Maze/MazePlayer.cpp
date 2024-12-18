#include "framework.h"
#include "MazePlayer.h"
#include "Contents/GameObject/Maze/Maze.h"
#include "Contents/GameObject/Maze/Block.h"
#include <stack>

MazePlayer::MazePlayer()
{
}

MazePlayer::~MazePlayer()
{
}

void MazePlayer::Update()
{
	if (_pathIndex >= _path.size())
		return;
	
	_time += 0.1f;
	if (_time > 1.0f)
	{
		_time -= 1.0f;
		if(_pos == _startPos)
			_maze->SetBlockType(_pos._y, _pos._x, Block::BlockType::START);
		else
			_maze->SetBlockType(_pos._y, _pos._x, Block::BlockType::FOOTPRINT);
		_pos = _path[_pathIndex];

		_pathIndex++;
	}
	
	_maze->SetBlockType(_pos._y, _pos._x, Block::BlockType::PLAYER);
}

void MazePlayer::SetMaze(shared_ptr<Maze> maze)
{
	_maze = maze;
}

void MazePlayer::Init()
{
	_pos = { 0,0 };
	_pathIndex = 0;
	_time = 0.0f;
	_dir = Dir::UP;
	_path.clear();

	if (_maze != nullptr)
	{
		_startPos = _maze->GetStartPos();
		_endPos = _maze->GetEndPos();
	}
	RightHand();
	//_maze->SetBlockType(_startPos._y, _startPos._x, Block::BlockType::START);
	_maze->SetBlockType(_endPos._y, _endPos._x, Block::BlockType::END);
}

void MazePlayer::RightHand()
{
	//우수법으로 갈 수 있는 경로(pos)들을 path에 담을 예정.
	_pos = _startPos;
	_path.push_back(_pos);

	Vector frontPos[4] = {
		Vector{ 0, -1}, //up
		Vector{-1,  0}, //left
		Vector{ 0,  1}, //down
		Vector{ 1,  0}, //right
	};

	while (true)
	{
		if (_pos == _endPos) {
			_path.push_back(_pos);
			break;
		}


		int newDir = (_dir - 1 + DIR_COUNT) % DIR_COUNT; // 오른쪽 회전
		Vector oldDirVector = frontPos[_dir]; //내 앞방향
		Vector newDirVector = frontPos[newDir]; //내 오른쪽

		Vector rightPos = _pos + newDirVector;
		Vector forwardPos = _pos + oldDirVector;
		if (CanGo(rightPos._y, rightPos._x))
		{
			_dir = static_cast<Dir>(newDir);
			_pos = rightPos;
			_path.push_back(_pos);
		}
		else if (CanGo(forwardPos._y, forwardPos._x))
		{
			_pos = forwardPos;
			_path.push_back(_pos);
		}
		else
		{
			int leftDir = (_dir + 1) % DIR_COUNT;
			_dir = static_cast<Dir>(leftDir);
		}
	}

	stack<Vector> s;
	for (int i = 0; i < _path.size() - 1; i++)
	{
		if (s.empty() == false && s.top() == _path[i + 1])
			s.pop();
		else
			s.push(_path[i]);
	}
	s.push(_path.back());
	_path.clear();
	while (true)
	{
		_path.push_back(s.top());
		s.pop();

		if (s.empty())
			break;
	}
	std::reverse(_path.begin(), _path.end());
	_pos = _startPos;
}

bool MazePlayer::CanGo(int y, int x)
{
	if (y >= MAX_Y || x >= MAX_X) return false;
	if (y < 0 || x < 0) return false;

	Block::BlockType type = _maze->GetBlockType(y, x);

	switch (type)
	{
	case Block::NONE:
		return false;
	case Block::ABLE:
		return true;
	case Block::DISABLE:
		return false;
	default:
		break;
	}
	return false;
}
