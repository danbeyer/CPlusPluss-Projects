/***********************************************************************************
** Program Filename: Holodeck.hpp
** Author: Daniel Beyer
** Date: 06/01/16
** Description: Class declaration file header for Holodeck.cpp
***************************************************************************/
#ifndef HOLODECK_HPP
#define HOLODECK_HPP
#include<iostream>
#include "Item.hpp"
#include "Player.hpp"
#include "Space.hpp"

class Holodeck : public Space
{
private:
	Item *item;
	bool isOn;
public:
	Holodeck() : Space("Holodeck")
	{
			item = new Item('G');	
			isOn = true;
	};
	void specialEnter(Player *player);
};
#endif // !HOLODECK_HPP
