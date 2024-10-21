#pragma once
class Mage : public Player
{

public:
	Mage(string name, int hp, int atk, int speed);

	virtual void Attack(Creature* target) override;

};

