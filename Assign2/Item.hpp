/***********************************************************************************
** Program Filename: Item.hpp
** Author: Daniel Beyer
** Date: 04/18/16
** Description: Class declaration file header for Item.cpp
***************************************************************************/
#ifndef ITEM_HPP
#define ITEM_HPP
#include<string>

using namespace std;

class Item
{
private:
	string itemName;
	string unit;
	int quantity;
	double price;

public:
	Item();
	Item(string, string, int, double);
	string getItemUnit();
	string getItemName();
	int getItemQuantity();
	double getItemPrice();
	double getItemTotal();


};

#endif 

