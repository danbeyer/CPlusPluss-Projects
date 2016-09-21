/***********************************************************************************
** Program Filename: Item.cpp
** Author: Daniel Beyer
** Date: 04*18/16
** Description: Implementation file for class functions in Item.hpp.
***************************************************************************/
#include<iostream>
#include<string>
#include "Item.hpp"

using namespace std;


/*************************************************************
** Function: Item
** Description: This is the default constructor for Item, it sets all variables to default values.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Item variables set to default values.
**********************************************************************/
Item::Item()
{
	itemName = " ";
	unit = " ";
	quantity = 0;
	price = 0.0;
}

/*************************************************************
** Function: Item
** Description: This is the user defined constructor for Item, it sets all variables to those defined by user.
** Parameters: string, string, in, double
** Pre-Conditions: None
** Post-Conditions: Item variables set to defined values.
**********************************************************************/
Item::Item(string name, string unit, int quantity, double price)
{
	this->itemName = name;
	this->unit = unit;
	this->quantity = quantity;
	this->price = price;
}

/*************************************************************
** Function: Getter functions
** Description: These are the getter functions for the Item variables
** Parameters: 
** Pre-Conditions: None
** Post-Conditions: None
**********************************************************************/

string Item::getItemName()
{
	return itemName;
}

string Item::getItemUnit()
{
	return unit;
}

int Item::getItemQuantity()
{
	return quantity;
}

double Item::getItemPrice()
{
	return price;
}

double Item::getItemTotal()
{
	return quantity * price;
}