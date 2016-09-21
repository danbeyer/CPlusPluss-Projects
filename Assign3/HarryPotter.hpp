/***********************************************************************************
** Program Filename: HarryPotter.hpp
** Author: Daniel Beyer
** Date: 05/04/16
** Description: Class declaration file header for HarryPotter.cpp
***************************************************************************/
#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP
#include "Creature.hpp"

class HarryPotter : public Creature
{
protected:

public:
	bool hasDied;
	HarryPotter();
	int Defend(int attackValue);
};
#endif // !HARRYPOTTER_HPP

