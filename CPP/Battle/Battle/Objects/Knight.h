#pragma once

//���� ����
class Goblin;

class Knight : public Player
{

public:
	Knight(string name, int hp, int atk);
	~Knight() { cout << "Delete Knight" << endl; }


	//�Լ� �����Ǵ� �Լ� �ñ״��İ� ���ƾ���.
	virtual void Attack (Creature* creature) override;

private:

};

