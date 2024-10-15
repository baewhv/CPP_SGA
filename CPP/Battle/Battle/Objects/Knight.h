#pragma once

//전방 선언
class Goblin;

class Knight : public Player
{

public:
	Knight(string name, int hp, int atk);
	~Knight() {}


	//함수 재정의는 함수 시그니쳐가 같아야함.
	virtual void Attack (Creature* creature) override;

private:

};

