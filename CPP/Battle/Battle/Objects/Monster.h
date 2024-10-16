#pragma once
class Monster : public Creature
{
public:
	Monster();
	Monster(string name, int hp, int atk);
	~Monster() { cout << "Delete Monster" << endl; }

private:

};

