#pragma once
class Goblin : public Monster
{
public:
	Goblin(string name);
	Goblin(int hp, int atk, int speed);

	virtual void Attack(Creature* target) override;

	virtual void hasDamaged(int damage) override;
	virtual bool isAlive() override;

};

