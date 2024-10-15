#pragma once
class Creature
{

public:
	Creature();

	//전방 선언
	//플레이어가 클래스라는것을 미리 알려줌.
	void Attack(class Player* p);
};

