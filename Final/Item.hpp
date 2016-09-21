/***********************************************************************************
** Program Filename: Item.hpp
** Author: Daniel Beyer
** Date: 05/04/16
** Description: Class declaration file header for Item.cpp
***************************************************************************/
#ifndef ITEM_HPP
#define ITEM_HPP
#include<iostream>
#include<string>

class Item
{
protected:
	char item;
public:
	Item();
	Item(char);
	char getItem();
};
#endif // !ITEM_HPP

