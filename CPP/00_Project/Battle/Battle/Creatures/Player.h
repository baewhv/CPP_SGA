#pragma once
class Player : public Creature
{
public:
	Player(string name, int hp, int atk, int spd) : Creature(name, hp, atk, spd) {}
	virtual ~Player() {}

	virtual bool isAlive() { return Creature::isAlive(); }

};

