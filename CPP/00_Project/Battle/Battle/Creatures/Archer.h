#pragma once
class Archer :
    public Player
{
public:
	Archer() : Player("Knight", 100 + rand() % 10, 10 + rand() % 5, 10 + rand() % 2) {}
	Archer(int a) : Player("Knight " + to_string(a), 100 + rand() % 10, 10 + rand() % 5, 10 + rand() % 2) {}
	virtual ~Archer() {}

	virtual bool isAlive() { return Player::isAlive(); }
};

