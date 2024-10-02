#include <iostream>

using namespace std;

struct Character
{
	int hp = 0;
	int atk = 0;
	int spd = 0;
	int coolTime = 0;
	string name = "";
	Character* target = nullptr;
};

void PrintCharacter(const Character* c)
{
	cout << c->name << "'s status" << endl;
	cout << c->name << "'s hp : " << c->hp << endl;
	cout << c->name << "'s atk : " << c->atk << endl;
	cout << c->name << "'s spd : " << c->spd << endl << endl;
}

void SetCharacter(Character* c, string name, int hp, int atk, int speed, Character* target)
{
	c->name = name;
	c->hp = hp;
	c->atk = atk;
	c->spd = speed;
	c->target = target;
}
void CheckAtk(Character* character)
{
	if (character->hp > 0 && character->coolTime >= 10)
	{
		cout << character->name << "'s attack! " << character->target->name << " has " << character->atk << " damaged." << endl;
		if (character->target->hp - character->atk > 0)
		{
			character->target->hp -= character->atk;
			cout << character->target->name << "'s hp : " << character->target->hp << endl;
			character->coolTime -= 10;
		}
		else
		{
			character->target->hp = 0;
			cout << character->target->name << "is defeated. " << character->name << "'s win." << endl;
		}
		cout << endl;
	}
	else
	{
		character->coolTime += character->spd;
	}
	
}

int main()
{
	Character* char1 = new Character();
	Character* char2 = new Character();

	SetCharacter(char1, "Breaker", 60, 12, 4, char2);
	SetCharacter(char2, "SoulEeater", 50, 10, 8, char1);

	PrintCharacter(char1);
	PrintCharacter(char2);

	while (char1->hp > 0 && char2->hp > 0)
	{
		if (char1->spd >= char2->spd)
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