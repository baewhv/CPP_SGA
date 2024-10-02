#include <iostream>

using namespace std;


class Player
{
public:
	Player(string name, int hp, int atk, int speed)
	{
		this->_name = name;
		this->_hp = hp;
		this->_atk = atk;
		this->_spd = speed;
		this->_coolTime = 0;
	}


	void PrintPlayer()
	{
		cout << this->_name << "'s status" << endl;
		cout << this->_name << "'s hp : " << this->_hp << endl;
		cout << this->_name << "'s atk : " << this->_atk << endl;
		cout << this->_name << "'s spd : " << this->_spd << endl << endl;
	}

	bool hasDamaged(int damage)
	{
		if (this->_hp - damage > 0)
		{
			this->_hp -= damage;
			return true;
		}
		else
		{
			this->_hp = 0;
			return false;
		}
	}
	void AddCoolTime(int ct)
	{
		_coolTime += ct;
	}
	
	int GetHp() { return _hp; }
	int GetAtk() { return _atk; }
	int GetSpd() { return _spd; }
	int GetCoolTime() { return _coolTime; }
	string GetName() { return _name; }
	Player* GetTarget() { return _target; }
	void SetTarget(Player* target) { this->_target = target; }

private:
	int _hp;
	int _atk;
	int _spd;
	int _coolTime;
	string _name;
	Player* _target = nullptr;
};

void CheckAtk(Player* p)
{
	if (p->GetHp() > 0 && p->GetCoolTime() >= 10)
	{
		cout << p->GetName() << "'s attack! " << p->GetTarget()->GetName() << " has " << p->GetAtk() << " damaged." << endl;
		p->GetTarget()->hasDamaged(p->GetAtk());
		if (p->GetTarget()->GetHp() > 0)
		{
			cout << p->GetTarget()->GetName() << "'s hp : " << p->GetTarget()->GetHp() << endl;
			p->AddCoolTime(-10);
		}
		else
		{
			cout << p->GetTarget()->GetName() << "is defeated. " << p->GetName() << "'s win." << endl;
		}
		cout << endl;
	}
	else
	{
		p->AddCoolTime(p->GetSpd());
	}

}

int main()
{
	Player* char1 = new Player("Breaker", 60, 12, 4);
	Player* char2 = new Player("SoulEater", 50, 10, 8);
	char1->SetTarget(char2);
	char2->SetTarget(char1);
	char1->PrintPlayer();
	char2->PrintPlayer();

	while (char1->GetHp() > 0 && char2->GetHp() > 0)
	{
		if (char1->GetSpd() >= char2->GetSpd())
		{
			CheckAtk(char1);
			CheckAtk(char2);
		}
		else
		{
			CheckAtk(char2);
			CheckAtk(char1);
		}
	}

	return 0;
}