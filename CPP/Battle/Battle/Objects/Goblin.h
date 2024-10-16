#pragma once
class Goblin : public Monster
{
public:
	Goblin(string name);
	~Goblin() { cout << "Delete Goblin" << endl; }

	virtual void Attack(class Creature* other) override;

private:

};

