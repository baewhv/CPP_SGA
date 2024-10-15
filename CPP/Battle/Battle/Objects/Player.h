#pragma once

class Player : public Creature
{
public:
	Player();
	Player(string name, int hp, int atk);

	void RangeAttack(Creature* arr[], int size)
	{
		for (int i = 0; i < size; i++)
		{
			this->Attack(arr[i]);
		}
	}

private:


};

