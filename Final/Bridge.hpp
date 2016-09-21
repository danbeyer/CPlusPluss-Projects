/***********************************************************************************
** Program Filename: Bridge.hpp
** Author: Daniel Beyer
** Date: 06/01/16
** Description: Class declaration file header for Bridge.cpp
***************************************************************************/
#ifndef BRIDGE_HPP
#define BRIDGE_HPP
#include<iostream>
#include "Item.hpp"
#include "Player.hpp"
#include "Space.hpp"

class Bridge : public Space
{
private:
	bool ensignInCharge;
public:
	Bridge() : Space("Bridge") {};
	void specialEnter(Player *player);
	bool getEnsigninCharge();

};
#endif // !BRIDGE_HPP
