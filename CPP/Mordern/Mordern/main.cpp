#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Modern C++ .. 11���� 
// 1. auto
// - Ÿ���߷�
// - �ݵ�� ����� ���ÿ� �ʱ�ȭ�� �ʿ��ϴ�.
// 
// ����
// - �������� ��������.
// 
// 2. �߰�ȣ �ʱ�ȭ
// 3. ������� for��
// 4. final, delete, defualt
// 5. friend


struct Vector
{
	int x;
	int y;
};

class Pet
{
	// friend
	friend class Warrior;

private:
	int _hp;
};

class Player
{
public:
	Player() = default; // ������, �Ҹ��ڿ����� ���δ�.
	Player(int hp, string name) : _hp(hp), _name(name) {}

	virtual void Attack() {}

protected:
	int _hp;
	string _name;
};

class Knight : public Player
{
public:
	Knight() {}
	Knight(int hp, string name) = delete;

	// final : �ڽĿ��� �������̵��� ���� �����Ѵ�.
	virtual void Attack() override final { cout << "Knight!" << endl; }
};

class Warrior : public Knight
{
public:
	void SetHp(int hp)
	{
		// pet�� hp�� ���� => friend
		_pet._hp = hp;
		_hp = hp;
	}

private:
	Pet _pet;
};

int main()
{
	unordered_map<string, int> um;
	um["hanil"] = 1;
	um["hanil2"] = 4;
	um["hanil3"] = 10;
	auto insertResult = um.insert(make_pair<string, int>("hanil4", 30));

	auto umIter = um.begin();

	for (umIter; umIter != um.end(); umIter++)
	{
		cout << "Name : " << umIter->first << " Value : " << umIter->second << endl;
		if (umIter->first == "hanil")
			umIter->second = 11111;
	}

	// �߰�ȣ �ʱ�ȭ
	int arr[3] = { 1,2,3 };
	int aInt = { 1 };

	Player p2;
	Player p = { 10, "hanil" };
	Vector v = { 1,1 };

	// unordered map�� key�� ���ó��
	cout << "������� for��" << endl;

	for (auto& p : um)
	{
		cout << "Name : " << p.first << " Value : " << p.second << endl;

		if (p.first == "hanil")
			p.second = 12341234;
	}

	return 0;
}