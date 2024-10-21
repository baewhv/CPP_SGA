#include "../framework.h"
#include "Creature.h"

Creature::Creature()
{
}

//전방 선언
//플레이어가 클래스라는것을 미리 알려줌.

inline void Creature::Attack(Player* p)
{
	//p->Attack(this);	//그러나 클래스라는것만 알지 내부 구조는 헤더에서는 모름.
}

