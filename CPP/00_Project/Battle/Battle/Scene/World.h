#pragma once
#include "Lobby.h"
#include "Forest.h"
#include "Forest.h"
#include "Forest.h"

enum class MapList
{
	LOBBY,
	TOWN,
	FOREST,
	CAVE
};


class World
{
public:
	World() {}
	virtual ~World() {}

	virtual void PlayScene() abstract;
};

