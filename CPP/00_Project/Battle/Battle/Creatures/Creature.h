#pragma once
class Creature
{
public:
	Creature(string name, int hp, int atk, int spd):
		_name(name), _hp(hp), _maxHp(_hp), _atk(atk), _spd(spd) {}
	virtual ~Creature()  {}

	virtual bool isAlive() { return _hp <= 0; }

protected:
	string _name;
	int _hp;
	int _maxHp;
	int _atk;
	int _spd;
};

