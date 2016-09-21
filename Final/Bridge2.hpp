/***********************************************************************************
** Program Filename: Bridge2.hpp
** Author: Daniel Beyer
** Date: 06/01/16
** Description: Class declaration file header for Bridge2.cpp
***************************************************************************/
#ifndef BRIDGE2_HPP
#define BRIDGE2_HPP
#include "Player.hpp"
#include "Item.hpp"
#include "Space.hpp"

class Bridge2 : public Space
{
private:
	Item *item;
	bool hasItem;
public:
	Bridge2() : Space("Bridge 2") 
	{
		item = new Item('Y');
		hasItem = true;
	};
	void specialEnter(Player *player);
};
#endif // !BRIDGE2_HPP

