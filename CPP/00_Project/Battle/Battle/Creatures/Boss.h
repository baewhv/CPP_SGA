#pragma once

struct Aggro
{
	Aggro(shared_ptr<Creature> c, int damage) : _ptr(c), _totalDamage(damage) {}
	weak_ptr<Creature> _ptr;
	int _totalDamage;
};

class Boss : public Goblin
{
public:
	Boss() : Goblin("Giant Goblin", 400 + rand() % 30, 50 + rand() % 8, 1) {}
	virtual ~Boss() {};
	
	virtual void Attack(shared_ptr<Creature> target) { Goblin::Attack(target); }
	virtual void GetDamage(int damage, shared_ptr<Creature> c) override;
	
	void Attack();

	//struct GetDamaged
	//{
	//	void operator()(int damage)
	//	{
	//		_boss->GetDamage(damage);
	//		for (auto ag = _boss->aggro.begin(); ag != _boss->aggro.end(); ag++)
	//		{
	//			if (_target == ag)
	//			{

	//			}
	//		}
	//		auto tg = _boss->aggro.find(_target);
	//		if (tg == _boss->aggro.end())
	//		{
	//			_boss->aggro.insert({ _target, damage });
	//		}
	//		else
	//		{
	//			tg->second += damage;
	//		}
	//	}
	//	shared_ptr<Creature> _target;
	//	Boss* _boss;
	//};
	

private:
	vector<Aggro> aggro;
};

