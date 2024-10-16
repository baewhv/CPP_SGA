#pragma once
class Knight : public Player
{
public:
	Knight(string name, int hp, int atk, int speed);
	
	virtual void Attack(Creature* target) override;
	virtual void hasDamaged(int damage) override;
	virtual bool isAlive() override;
};

