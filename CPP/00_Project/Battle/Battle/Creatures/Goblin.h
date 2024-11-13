#pragma once
class Goblin:public Monster
{
public:
	Goblin(int num) : Monster("Goblin " + to_string(num), 10 + rand() % 10, 3 + rand() % 5, 1 + rand() % 4) {}
	Goblin(string name, int hp, int atk, int spd) : Monster(name, hp, atk, spd) {}
	virtual ~Goblin() {}

	virtual void GetDamage(int damage, shared_ptr<Creature> c) { Creature::GetDamage(damage, c); }

};

