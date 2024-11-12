#pragma once

//using ATKFUNC = void(*)(int);

typedef void(*ATKFUNC)(int);

//using ATKFUNC = std::function<void(int)>;

class Creature
{
public:
	Creature(string name, int hp, int atk, int spd) :
		_name(name), _hp(hp), _maxHp(_hp), _atk(atk), _spd(spd), _func(nullptr) {}
	virtual ~Creature() {}

	virtual bool isAlive() { return _hp > 0; }

	void PrintCreature();

	void SetName(string name) { _name = name; }

	virtual void Attack(Creature* c, function<void(int)> func = nullptr);
	void GetDamage(int damage);

protected:
	string _name;
	int _hp;
	int _maxHp;
	int _atk;
	int _spd;

	function<void(int)> _func;
};

