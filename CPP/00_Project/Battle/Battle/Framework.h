#pragma once

#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <functional>
#include <algorithm>

using namespace std;

#include "Manager/InputManager.h"
#include "Manager/GameManager.h"
#include "Creatures/Creatures.h"
#include "Scene/SceneList.h"

#define GETPLAYER GameManager::GetInstance()->GetPlayer()
#define CLS InputManager::GetInstance()->ClearScrean()