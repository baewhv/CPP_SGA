#pragma once
class Creature
{

public:
	Creature();

	virtual void Attack(class Creature* target) abstract;

	Creature(string name, int hp, int atk, int spd);

	void Print();

	bool CheckAtk();

	virtual void hasDamaged(int damage) abstract;
	virtual bool isAlive() abstract { return _hp > 0; }

	void AddCoolTime(int ct) { _coolTime += ct; }

	int GetMaxHp() { return _maxHp; }
	int GetHp() { return _hp; }
	

	int GetAtk() { return _atk; }
	int GetSpd() { return _spd; }
	int GetCoolTime() { return _coolTime; }
	string GetName() { return _name; }

protected:
	int _maxHp;
	int _hp;
	int _atk;
	int _spd;
	int _coolTime;
	string _name;
};

