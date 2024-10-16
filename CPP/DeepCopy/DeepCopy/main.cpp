#include <iostream>

using namespace std;

class Pet
{
public:
	void Attack() 
	{
		cout << "Pet Attack" << endl;
	}

	int _hp;
	int _atk;
};

class Player
{
public:
	Player() : _hp(0), _pet(new Pet()) {}

	//���������. �Ͻ������� �ڵ� ������.

	Player(const Player& other)
		: _hp(other._hp)
	{
		if (_pet != nullptr)
		{
			*_pet = *other._pet; //���� ���� ����.
		}
		else
		{
			_pet = new Pet(*other._pet);
			//*_pet = *other._pet;
		}

	}

	~Player() { delete _pet; }


	//���� ������ ��� ����.(����)
	//Player& operator=(const Player& other) = delete;


	Player& operator=(const Player& other)
	{
		_hp = other._hp;
		//_pet = other._pet;

		if (_pet != nullptr)
		{
			*_pet = *other._pet; //���� ���� ����.
		}
		else
		{
			_pet = new Pet(*other._pet);
			//_pet = new Pet();
			//*_pet = *other._pet;
		}

		return (*this);
	}

	void Attack()
	{
		cout << "Player Attack" <<endl;
		if (_pet != nullptr)
		{
			_pet->Attack();
		}
	}
private:
	int _hp;
	Pet* _pet;
};

int main()
{
	// new delete :������ ������ ����. (UAF, Use After Free)

	Player* p1 = new Player();
	//Player* p2 = new Player();
	Player* p2 = new Player(*p1);

	*p2 = *p1;

	p1->Attack();

	delete p2;
	delete p1;

	return 0;
}