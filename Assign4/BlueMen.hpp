/***********************************************************************************
** Program Filename: BlueMen.hpp
** Author: Daniel Beyer
** Date: 05/04/16
** Description: Class declaration file header for BlueMen.cpp
***************************************************************************/
#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP
#include<string>
#include "Creature.hpp"

class BlueMen : public Creature
{
protected:

public:
	BlueMen();
	BlueMen(string name);
	int Attack();
	int Defend(int attackValue);
};
#endif // !BLUEMEN_HPP

