#pragma once
class Player
{
public:
	Player();
	void init(int health,int attack,int defense,int agility);
	void setPosition(int newX, int newY);//sets the x and y.
	void getPosition(int &currX,int &currY);//retrieves the current x and y position of the player.
	void getStats(int &health,int &attack,int &defense);
	void printPosition();//print out the character's position on the map.
	int getX();
	int getY();
	int getHp();
	void setHp(int i);
private:
	//player icon
	char p;
	//player current location.
	int x,y;
	//player stats
	int hp;
	int atk;
	int def;
	int agil;
};

