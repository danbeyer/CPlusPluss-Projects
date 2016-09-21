/***********************************************************************************
** Program Filename: Barbarian.hpp
** Author: Daniel Beyer
** Date: 05/04/16
** Description: Class declaration file header for Barbarian.cpp
***************************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#include<string>
#include "Creature.hpp"

class Barbarian : public Creature
{
protected:

public:
	Barbarian();
	Barbarian(string name);
	int Attack();
	int Defend(int attackValue);

};
#endif // !BARBARIAN_HPP

