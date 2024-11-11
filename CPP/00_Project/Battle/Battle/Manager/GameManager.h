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
	void CreatePlayer();
	void SelectLocation();
	void LoadScene();

private:
	GameManager() : _p(nullptr), _w(nullptr) {}
	~GameManager() {}
	GameManager(const GameManager& other) : _p(nullptr), _w(nullptr) {};
	GameManager& operator =(const GameManager& other) {}

	static GameManager* _inst;
	class Creature* _p;
	class World* _w;
};

