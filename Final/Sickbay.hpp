/***********************************************************************************
** Program Filename: Sickbay.hpp
** Author: Daniel Beyer
** Date: 06/01/16
** Description: Class declaration file header for Sickbay.cpp
***************************************************************************/
#ifndef SICKBAY_HPP
#define SICKBAY_HPP
#include "Player.hpp"
#include "Item.hpp"
#include "Space.hpp"

class Sickbay : public Space
{
private:
	Item *item;
	bool hasItem;
public:
	Sickbay() : Space("Sickbay") 
	{
		item = new Item('R');
		hasItem = true;
	};
	void specialEnter(Player *player);
};
#endif // !SICKBAY_HPP
