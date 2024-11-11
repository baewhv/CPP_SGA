#pragma once

class Boss : public Goblin
{
public:
	Boss() : Goblin("Giant Goblin", 200 + rand() % 30, 15 + rand() % 8, 1) {}
	virtual ~Boss() {};
	
	virtual void Attack(Creature* target, ATKFUNC func = nullptr) { Goblin::Attack(target, func); }
	virtual void GetDamage(int damage) { Goblin::GetDamage(damage); }
	
	void Attack();

	struct GetDamaged
	{
		void operator()(int damage)
		{
			_boss->GetDamage(damage);
			auto tg = _boss->aggro.find(_target);
			if (tg == _boss->aggro.end())
			{
				_boss->aggro.insert({ _target, damage });
			}
			else
			{
				tg->second += damage;
			}
		}
		Creature* _target;
		Boss* _boss;
	};
	

private:
	map<Creature*, int> aggro;
};

