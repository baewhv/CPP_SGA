#pragma once
class Archer : public Player
{
public:
	Archer(string name, int hp, int atk, int speed);

	virtual void Attack(Creature* target) override;

};

