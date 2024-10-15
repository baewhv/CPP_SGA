#pragma once
class World
{
public:
	World();
	~World();
	void Init();

	void Update();
	bool End();


private:
	bool CheckCreatureArr();

	Creature* _player;
	Creature* _monster[10];

};

