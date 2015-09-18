#include "Enemy.h"
#include <iostream>

using namespace std;

Enemy::Enemy(void)
{
	//exp points 7
	exp = 7;
}

void Enemy::init(int health,int attack,int defense,int agility)
{
	hp = health;
	atk = attack;
	def = defense;
	agil = agility;
}

void Enemy::getPosition(int &cx, int &cy)
{
	cx = x;
	cy = y;
}

void Enemy::setPosition(int tx,int ty)
{
	x = tx;
	y = ty;
}

int Enemy::getX()
{
	return x;
}

int Enemy::getY()
{
	return y;
}

void Enemy::printPosition()
{
	printf("Enemy coordinates: (%d,%d)\n",x,y);
}

int Enemy::getHp()
{
	return hp;
}

void Enemy::setHp(int i)
{
	hp = i;
}

void Enemy::getStats(int &health,int &attack,int &defense)
{
	health = hp;
	attack = atk;
	defense = def;
}