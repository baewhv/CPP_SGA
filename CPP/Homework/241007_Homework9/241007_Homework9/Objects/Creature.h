#pragma once
class Creature
{

public:
	Creature();

	bool Attack(class Creature* p);

	Creature(string name, int hp, int atk, int spd);

	void Print();

	bool CheckAtk();

	void hasDamaged(int damage);
	void AddCoolTime(int ct) { _coolTime += ct; }
	int GetMaxHp() { return _maxHp; }
	int GetHp() { return _hp; }
	int GetAtk() { return _atk; }
	int GetSpd() { return _spd; }
	int GetCoolTime() { return _coolTime; }
	string GetName() { return _name; }
	Creature* GetTarget() { return _target; }
	void SetTarget(Creature* target) { this->_target = target; }

private:
	int _maxHp;
	int _hp;
	int _atk;
	int _spd;
	int _coolTime;
	string _name;
	Creature* _target = nullptr;
};

