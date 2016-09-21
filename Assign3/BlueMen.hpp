/***********************************************************************************
** Program Filename: BlueMen.hpp
** Author: Daniel Beyer
** Date: 05/04/16
** Description: Class declaration file header for BlueMen.cpp
***************************************************************************/
#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP
#include "Creature.hpp"

class BlueMen : public Creature
{
protected:

public:
	BlueMen();
	int Defend(int attackValue);
};
#endif // !BLUEMEN_HPP

