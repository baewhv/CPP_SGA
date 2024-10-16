#pragma once

class Player : public Creature
{
public:
	Player();
	Player(string name, int hp, int atk);
	~Player() { cout << "Delete Player" << endl; }

	void RangeAttack(Creature* arr[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			this->Attack(arr[i]);
		}
	}

private:


};

