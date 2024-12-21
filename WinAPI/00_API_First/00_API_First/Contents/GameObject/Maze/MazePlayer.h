#pragma once
class Maze;
class MazePlayer
{
public:
	enum Dir {
		UP,
		LEFT,
		DOWN,
		RIGHT,
		DIR_COUNT = 4,
	};

	MazePlayer();
	~MazePlayer();
	void Update();

	void SetMaze(shared_ptr<Maze> maze);
	void Init();

	void RightHand();
	void DFS();
	bool CanGo(int y, int x);

private:
	shared_ptr<Maze> _maze;

	Dir _dir = Dir::UP;
	Vector _pos = { 1,1 };//현재 위치
	Vector _startPos = {};
	Vector _endPos = {};

	int _pathIndex = 0;
	float _time = 1.1f;
	vector<Vector> _path;
	bool setDFS = false;
};

