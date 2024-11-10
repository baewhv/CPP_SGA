#pragma once
class GameManager
{
public:
	static GameManager* GetInstance()
	{
		if (_inst == nullptr)
		{
			_inst = new GameManager();
		}
		return _inst;
	}
	class Creature* GetPlayer();
	void SetPlayer(class Creature* p);
	void CreatePlayer();
	void LoadScene(MapList m);



private:
	GameManager() : _p(nullptr), _w(nullptr) {}
	~GameManager() {}
	GameManager(const GameManager& other) : _p(nullptr), _w(nullptr) {};
	GameManager& operator =(const GameManager& other) {}

	static GameManager* _inst;
	class Creature* _p;
	class World* _w;
};

