/***********************************************************************************
** Program Filename: Item.cpp
** Author: Daniel Beyer
** Date: 05/04/16
** Description: Implementation file for class functions in Item.hpp.
***************************************************************************/
#include<iostream>
#include<string>
#include "Item.hpp"

Item::Item()
{
	item = 'x';
}

Item::Item(char i)
{
	item = i;
}

char Item::getItem()
{
	return item;
}