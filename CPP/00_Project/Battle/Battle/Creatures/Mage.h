#pragma once
class Mage :
    public Player
{
public:
	Mage() : Player("Mage", 100 + rand() % 10, 10 + rand() % 5, 10 + rand() % 2) {}
	Mage(int a) : Player("Mage " + to_string(a), 100 + rand() % 10, 10 + rand() % 5, 10 + rand() % 2) {}
	virtual ~Mage() {}


};

