#include "Player.h"
#include <iostream>
#include <conio.h>

using namespace std;

Player::Player()
{
}

void Player::init(int health,int attack,int defense,int agility)
{
	hp = health;
	atk = attack;
	def = defense;
	agil = agility;
	p = 'p';
	x = 0;
	y = 0;
}

//equivalent to getX and getY
void Player::getPosition(int &currX,int &currY)
{
	currX = x;
	currY = y;
}

void Player::setPosition(int newX, int newY)
{
	x = newX;
	y = newY;
}

void Player::printPosition()
{
	printf("Player coordinates: (%d, %d)\n",x,y);
}

int Player::getX()
{
	return x;
}

int Player::getY()
{
	return y;
}

int Player::getHp()
{
	return hp;
}

void Player::setHp(int i)
{
	hp = i;
}

void Player::getStats(int &health,int &attack,int &defense)
{
	health = hp;
	attack = atk;
	defense = def;
}




