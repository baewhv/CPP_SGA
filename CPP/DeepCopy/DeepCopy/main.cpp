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

	//복사생성자. 암시적으로 자동 생성됨.

	Player(const Player& other)
		: _hp(other._hp)
	{
		if (_pet != nullptr)
		{
			*_pet = *other._pet; //펫의 값만 복사.
		}
		else
		{
			_pet = new Pet(*other._pet);
			//*_pet = *other._pet;
		}

	}

	~Player() { delete _pet; }


	//복사 생성자 사용 제한.(삭제)
	//Player& operator=(const Player& other) = delete;


	Player& operator=(const Player& other)
	{
		_hp = other._hp;
		//_pet = other._pet;

		if (_pet != nullptr)
		{
			*_pet = *other._pet; //펫의 값만 복사.
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
	// new delete :삭제는 생성의 역순. (UAF, Use After Free)

	Player* p1 = new Player();
	//Player* p2 = new Player();
	Player* p2 = new Player(*p1);

	*p2 = *p1;

	p1->Attack();

	delete p2;
	delete p1;

	return 0;
}