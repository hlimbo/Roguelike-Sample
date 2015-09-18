#pragma once
#include <string>
#include <vector>

#include "Map.h"
#include "Player.h"
#include "Enemy.h"

//could make a level class to hold player, enemies, and other interactable objects in game.
class GameManager
{
public:
	GameManager(string filename);
	void start();
	void stop();
private:
	Map MainMap;
	Player _player;
	Enemy _enemy;
	bool running;
};

