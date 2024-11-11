#pragma once
class Monster : public Creature
{
public:
	Monster(string name, int hp, int atk, int spd) : Creature(name, hp, atk, spd) {}
	virtual ~Monster() {}
};

