#pragma once
class Enemy
{
public:
	Enemy(void);
	void init(int health,int attack,int defense, int agility);
	void getPosition(int &cx, int &cy);//returns the curr x and y position.
	void setPosition(int tx,int ty);
	void getStats(int &health,int &attack,int &defense);
	int getX();//im used to coding in java...
	int getY();
	void printPosition();
	int getHp();
	void setHp(int i);
private:
	//x-y coordinates
	int x,y;
	//enemy stats
	int hp;
	int atk;
	int def;
	int agil;
	int exp;

};

