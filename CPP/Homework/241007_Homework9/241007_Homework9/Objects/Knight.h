#pragma once
class Knight : public Player
{
public:
	Knight(string name, int hp, int atk, int speed);
	
	bool Attack(Creature* target);
};

