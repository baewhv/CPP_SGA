#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Modern C++ .. 11이후 
// 1. auto
// - 타입추론
// - 반드시 선언과 동시에 초기화가 필요하다.
// 
// 단점
// - 가독성이 떨어진다.
// 
// 2. 중괄호 초기화
// 3. 범위기반 for문
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
	Player() = default; // 생성자, 소멸자에서만 쓰인다.
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

	// final : 자식에서 오버라이딩을 이제 금지한다.
	virtual void Attack() override final { cout << "Knight!" << endl; }
};

class Warrior : public Knight
{
public:
	void SetHp(int hp)
	{
		// pet의 hp도 수정 => friend
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

	// 중괄호 초기화
	int arr[3] = { 1,2,3 };
	int aInt = { 1 };

	Player p2;
	Player p = { 10, "hanil" };
	Vector v = { 1,1 };

	// unordered map의 key는 상수처리
	cout << "범위기반 for문" << endl;

	for (auto& p : um)
	{
		cout << "Name : " << p.first << " Value : " << p.second << endl;

		if (p.first == "hanil")
			p.second = 12341234;
	}

	return 0;
}