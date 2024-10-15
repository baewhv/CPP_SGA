#pragma once
class Goblin : public Monster
{
public:
	Goblin(string name);
	~Goblin();

	virtual void Attack(class Creature* other) override;

private:

};

