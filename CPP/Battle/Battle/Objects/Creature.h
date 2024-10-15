#pragma once
class Creature
{

public:
	Creature() :_name(""), _hp(0), _maxHp(0), _atk(0) {}
	Creature(string name, int hp, int atk);
	~Creature();

	void PrintInfo();
	virtual void Attack(Creature* other);
	void TakeDamage(int amount);


	bool IsDead() { return _hp <= 0; }

	const string& GetName() { return _name; }

protected:
	int _hp;
	int _atk;
	int _maxHp;
	string _name;
};

