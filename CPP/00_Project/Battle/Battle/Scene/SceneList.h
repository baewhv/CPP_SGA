#pragma once

#include "World.h"
#include "Lobby.h"
#include "Forest.h"
#include "Town.h"
#include "Cave.h"

#ifndef MAPLIST
#define MAPLIST
enum class MapList
{
	LOBBY,
	TOWN,
	FOREST,
	CAVE
};
#endif // !MAPLIST
