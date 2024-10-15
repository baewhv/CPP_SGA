#include "Framework.h"
#include "World.h"

World::World()
{
	Init();
}

World::~World()
{
}

void World::Init()
{
	_player = new Knight("Link", 1000, 10);

	for (int i = 0; i < 10; i++)
	{
		_monster[i] = new Goblin("Goblin" + to_string(i));
	}
}

void World::Update()
{
	((Player*)_player)->RangeAttack(_monster, 10);

	for (int i = 0; i < 10; i++)
	{
		_monster[i]->Attack(_player);
	}
}

bool World::End()
{
	if (_player->IsDead())
	{
		cout << "Player die" << endl;
		return true;
	}
	if (CheckCreatureArr())
	{
		cout << "Monsters die" << endl;
		return true;
	}
	return false;
}

bool World::CheckCreatureArr()
{
	for (int i = 0; i < 10; i++)
	{
		if (_monster[i]->IsDead() == false)
		{
			return false;
		}
	}
	return true;
}
