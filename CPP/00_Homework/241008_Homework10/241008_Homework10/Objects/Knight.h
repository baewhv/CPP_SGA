#pragma once
class Knight : public Player
{
public:
	Knight(string name, int hp, int atk, int speed);
	
	virtual void Attack(Creature* target) override;
};

