/***********************************************************************************
** Program Filename: tenforward.hpp
** Author: Daniel Beyer
** Date: 06/01/16
** Description: Class declaration file header for tenforward.cpp
***************************************************************************/
#ifndef TENFORWARD_HPP
#define TENFORWARD_HPP
#include<iostream>
#include "Item.hpp"
#include "Player.hpp"
#include "Space.hpp"

class Tenforward : public Space
{
private:
	Item *item;
	Item *item2;
	Item *item3;
	bool hasItem;
	
public:
	Tenforward() : Space("Tenforward")
	{
		item = new Item('B');
		item2 = new Item('P');
		item3 = new Item('W');
		hasItem = true;
	};

	void specialEnter(Player *player);
};
#endif // !TENFORWARD_HPP
