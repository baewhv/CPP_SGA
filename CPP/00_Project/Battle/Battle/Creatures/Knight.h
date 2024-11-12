#pragma once

class Knight :
	public Player
{
public:
	Knight() : Player("Knight", 100 + rand() % 10, 10 + rand() % 5, 10 + rand() % 2) {}
	Knight(int a) : Player("Knight "+to_string(a), 100 + rand() % 10, 10 + rand() % 5, 10 + rand() % 2) {}
	virtual ~Knight() {}

	virtual bool isAlive() { return Player::isAlive(); }

};

