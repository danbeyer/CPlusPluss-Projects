/***********************************************************************************
** Program Filename: Inventory.hpp
** Author: Daniel Beyer
** Date: 06/01/16
** Description: Class declaration file header for Inventory.cpp
***************************************************************************/
#ifndef INVENTORY_HPP
#define INVENTORY_HPP
#include "Item.hpp"
#include<string>

class Inventory
{
protected:
	int numItems;
	int maxItems;
	Item *items[5];
	std::string name;

public:
	Inventory();
	~Inventory();
	void addItem(Item *newItem);
	void removeItem(int itemNum);
	void display();
	Item* useItem(int itemNum);
	int getNumItems();
};
#endif // !INVENTORY_HPP
