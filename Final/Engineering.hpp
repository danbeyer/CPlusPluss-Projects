/***********************************************************************************
** Program Filename: Engineering.hpp
** Author: Daniel Beyer
** Date: 06/01/16
** Description: Class declaration file header for Engineering.cpp
***************************************************************************/
#ifndef ENGINEERING_HPP
#define ENGINEERING_HPP
#include "Player.hpp"
#include "Item.hpp"
#include "Space.hpp"

class Engineering : public Space
{
private:
	

public:
	Engineering() : Space("Engineering") {};
	void specialEnter(Player *player);
};
#endif // !ENGRINEERING_HPP

