#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Console.h"

#include "GameManager.h"
#include "Map.h"
#include "Player.h"

using namespace std;

GameManager::GameManager(string filename)
{
	running = true;
	MainMap.init(filename);
	_player.init(10,25,4,10);
	_enemy.init(65,4,10,10);
	MainMap.findPlayer(_player);
	MainMap.findEnemy(_enemy);
	//_player.printPosition();
	//_enemy.printPosition();
	
}

//gameloop
void GameManager::start()
{
	while(running)
	{
		MainMap.getInput(_player);
		MainMap.fight(_player,_enemy);
		MainMap.print();
	}
}

void GameManager::stop()
{
	running = false;
}
