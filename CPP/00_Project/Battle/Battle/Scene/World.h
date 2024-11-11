#pragma once

class World
{
public:
	World() {}
	virtual ~World() {}

	virtual void PlayScene() abstract;
};

