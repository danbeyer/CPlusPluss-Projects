/***********************************************************************************
** Program Filename: HarryPotter.hpp
** Author: Daniel Beyer
** Date: 05/04/16
** Description: Class declaration file header for HarryPotter.cpp
***************************************************************************/
#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP
#include<string>
#include "Creature.hpp"

class HarryPotter : public Creature
{
protected:

public:
	bool hasDied;
	HarryPotter();
	HarryPotter(string name);
	int Defend(int attackValue);
	int Attack();
};
#endif // !HARRYPOTTER_HPP

