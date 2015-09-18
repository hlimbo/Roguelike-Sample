#pragma once
#include <string>
#include <vector>

#include "Player.h"
#include "Enemy.h"

using namespace std;
class Map
{
public:
	Map();
	void init(string filename);
	void print();//prints map.
	void findPlayer(Player &player);
	void findEnemy(Enemy &enemy);
	char getTile(int x,int y);
	void setTile(int x,int y,char &tile);
	void getInput(Player &player);
	bool canMove(Player player,int nextX,int nextY);
	bool canFight(Player player,int nextX,int nextY);
	void fight(Player player,Enemy enemy);
private:
	vector<string> leveldata;

};

