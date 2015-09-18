#include "Map.h"
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

#include "Player.h"
#include "Enemy.h"

using namespace std;

Map::Map()
{
}

//load map file - read it.
void Map::init(string filename)
{
    ifstream ifile;
	string line;
	ifile.open(filename);
	if(ifile.fail())
	{
		perror(filename.c_str());
		return;
	}

	//read the map one line at a time.
	while(getline(ifile,line))
	{
		//store contents into a vector.
		leveldata.push_back(line);
	}

	ifile.close();

}

//print map;
void Map::print()
{
	for(int i = 0;i < (signed)leveldata.size();i++)
	{

		printf("%s\n",leveldata[i].c_str());
		//cout << leveldata[i] << endl;
	}

}

//set find the player on the map at start and get its initial location.
void Map::findPlayer(Player &player)
{
	for(int i = 0; i < (signed)leveldata.size();i++)
	{
		for(int j = 0;j < (signed)leveldata[i].size();j++)
		{
			if(leveldata[i][j] == 'p')
			{
				player.setPosition(i,j);
				return;
			}
		}
	}
}

//extend this function by accepting a list/vector of enemies.
void Map::findEnemy(Enemy &enemy)
{
	for(int i = 0; i < (signed)leveldata.size();i++)
	{
		for(int j = 0;j < (signed)leveldata[i].size();j++)
		{
			if(leveldata[i][j] == 'e')
			{
				enemy.setPosition(i,j);
				return;
			}
		}
	}
}

char Map::getTile(int x,int y)
{
	return leveldata[y][x];
}

void Map::setTile(int x,int y,char &tile)
{
	leveldata[y][x] = tile;
}

//player movement.
void Map::getInput(Player &player)
{
	char keyinput;
	int newX,newY;
	int dx= 0, dy = 0;

	//obtain the curr x and y of player.
	player.getPosition(newX,newY);
	keyinput = _getch();
	switch(keyinput)
	{
		case 'w':
			dy = -1;
			break;
		case 's':
			dy = 1;
			break;
		case 'a':
			dx = -1;
			break;
		case 'd':
			dx = 1;
			break;
		default:
			break;
	}
	
	//updates the movement based on keyinput
	newX += dx;
	newY += dy;

	if(canMove(player,newX,newY))
	{
		//replacement tile
		char tile = getTile(newX,newY);
		//player tile.
		char p = getTile(player.getX(),player.getY());
		//tile replacing player
		setTile(player.getX(),player.getY(),tile);
		//player replacing tile
		setTile(newX,newY,p);
		//updates the position of player.
		player.setPosition(newX,newY);
	}
		//cout <<string(20,'\n');
}

bool Map::canMove(Player player,int nextX,int nextY)
{
	char nextTile = getTile(nextX,nextY);
	//floor
	if(nextTile == '-')
		return true;
	else
		return false;
}

bool Map::canFight(Player player, int nextX, int nextY)
{
	char nexttile = getTile(nextX,nextY);
	if(nexttile == 'e')
		return true;

	return false;
}

//crude fighting function.
void Map::fight(Player player,Enemy enemy)
{
	char input = _getch();
	int targetX,targetY;
	bool isfighting = false;
	
	player.getPosition(targetX,targetY);
	if(input == 'f')
	{
		//check to see if the enemy is one block away from player.
		if(canFight(player,targetX+1,targetY) || 
			canFight(player,targetX-1,targetY) ||
			canFight(player,targetX,targetY-1) ||
			canFight(player,targetX,targetY+1)
			)
		{
			isfighting = true;
		}
	}

	if(isfighting)
	{
		//player stats 
		int php;
		int patk;
		int pdef;

		//enemy stats
		int ehp;
		int eatk;
		int edef;

		//get initial stats
		player.getStats(php,patk,pdef);
		enemy.getStats(ehp,eatk,edef);

		int pdmg = patk - edef;
		int edmg = eatk - pdef;

		while(php > 0 && ehp > 0)
		{

			
			//player attack.
			ehp = ehp - pdmg;
			//enemy attack.
			php = php - edmg;

			//setting hp = 0 if it goes negative
			if(php < 0)
				php = 0;
			if(ehp < 0)
				ehp = 0;


			//display fight
			printf("Player attacks for %d on enemy's hp\n",pdmg);
			printf("Enemy attacks for %d on player's hp\n",edmg);
			printf("Player hp: %d\n",php);
			printf("Enemy hp: %d\n",ehp);

			player.setHp(php);
			enemy.setHp(ehp);
		}
		isfighting = false;
	}
	//a dice is used to simulate combat (1-6);
	/*
		ATTACK
		1 - 10% of attack damage applied.
		2 - 15% of attack damage applied.
		3 - 25% of attack damage applied.
		4 - 30% of attack damage applied.
		5 - 45% of attack damage applied.
		6 - 75% of attack damage applied.

		DEFENSE
		1 - 10% of damage received.
		2 - 15% of damage received.
		3 - 25% of damage received.
		4 - 30% of damage received.
		5 - 35% of damage received.
		6 - 55% of damage received.
	*/
	/*
		FORMULA for calculating hp remaining after nth attack.
		player_dmg = player attack * damage %
		enemy_dmg = enemy attack * damage %
		
		//simple one without percentages of attack damage being involved.
		player hp = current hp - (enemy attack - player defense);
		enemy hp = current hp - (player attack - enemy defense);
	*/
	//procedure
	/*
		1. player rolls dice for attack
		2. enemy rolls dice for attack
		3. player rolls dice for defense
		4. enemy rolls dice for defense
		5. player attacks enemy.
		6. enemy attacks player
		7. repeat until enemy or player reaches 0 hp.
	*/
}

