#include <iostream>

using namespace std;

// shift : �̵� = move

// lvalue : ������ �� �ִ� ���� (����)
// rvalue : lvalue�� �ƴ� ��. ���� ������ �� ���� ��(���) = �ӽ� ��, �ӽ� ��ü.

// ���� �� ������: lValue�� rValue�� ����.
// -> lValue�� �����⸸ �����.

class Pet
{

};


class Player
{
public:
	Player() : _pet(new Pet()) { cout << "�⺻ ������" << endl; }
	Player(int hp) : _hp(hp), _pet(new Pet()) { cout << "Ÿ�� ��ȯ ������" << endl; }
	Player(const Player& other) : _hp(other._hp), _pet(new Pet(*other._pet)) { cout << "���� ������" << endl; }


	//�̵� ������
	//other �� ��� ���� ���⿡ �ű�� other�� �����⸸ �����.
	//��� ���ϱ�?
	//ũ�Ⱑ ū Ŭ������ ���빰�� �̵��Ϸ� �� ��.
	//�̸� ���� ���� �� ������� �޸𸮰� �׸�ŭ �ʿ�. & �ʱ�ȭ�� �� �Ͼ.

	Player(Player&& other) noexcept
	{
		cout << "�̵� ������" << endl;
		_hp = other._hp;
		_pet = other._pet;

		other._pet = nullptr;
	}


	~Player() 
	{
		if(_pet != nullptr)
			delete _pet; 
		cout << "�Ҹ��� ȣ��" << endl;
	}

	Player& operator=(const Player& other)
	{
		_hp = other._hp;
		_pet = other._pet;

		return this;
	}
	
	int _hp = 0;
	Pet* _pet;
};

//Call by Value
//1. ������ ������ ���� �ʴ´�.

void Func(Player p) 
{
	p = Player(5);

	Player p = Player(5); //Ÿ�Ժ�ȯ������
}

//Call by Address
//1. �������� ����.
//2. ������ ���� �����ϴ�.
//3. ���� ��ƴ�.
	//��� �����Ϳ� �����ϰ��ִ��� ��.
void Func(Player* p)
{
	
}

// Call by Ref
// 1. ���� ����� ����.
// 2. ���� ������ �����ϴ�.
// 3. 
// 4. ���� ��(nullptr) Ȥ�� �ӽ� ��ü�� �ѱ� �� ����.
void FuncRef(Player& p)
{

}

int main()
{
	// 10 = 5; 10 -> ������ �� ���� ��. = rValue;
	//int(10) = 5; -> �ӽ� ��ü. ���� ������ �������.

	//Player()._hp = 10; //Player() : �̸��� ���� ��ü.

	//Player&&(); // ������ ����

	Player* p = new Player();
	Player* p2 = new Player(*p);

	Player* p3 = new Player(std::move(*p2));

	//�� �ϳ��� �����ؾ� �ϴ� ptr
	//unique_ptr<Player> unique_p = make_unique<Player>(1);
	//unique_ptr<Player> unique_p2 = std::move(unique_p);

	delete p;
	delete p2;
	delete p3;

	Func(*new Player());

	return 0 ;
}