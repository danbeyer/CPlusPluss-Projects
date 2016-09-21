/***********************************************************************************
** Program Filename: Player.hpp
** Author: Daniel Beyer
** Date: 06/01/16
** Description: Class declaration file header for Player.cpp
***************************************************************************/
#ifndef PLAYER_HPP
#define PLAYER_HPP
#include<iostream>
#include<string>
class Space;
class Inventory;



class Player
{
private:
	Space *location;
	Inventory *backpack;
	char savedShip;
	char ensignInCharge;
	char bridgeBlewUp;

public:
	Player();
	Space* getLocation();
	void setLocation(Space *space);
	Inventory* getInventory();
	char getsaved();
	void setSaved(char);
	void setEnsignInCharge(char);
	void setBridgeBlewUp(char);
	char getEnsignInCharge();
	char getBridgeBlewUp();
	~Player();
};
#endif // !PLAYER_HPP

