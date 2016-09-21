/***********************************************************************************
** Program Filename: Medusa.hpp
** Author: Daniel Beyer
** Date: 05/04/16
** Description: Class declaration file header for Medusa.cpp
***************************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP
#include<string>
#include "Creature.hpp"

class Medusa : public Creature
{
protected:

public:
	Medusa();
	int Attack();


};

#endif // !MEDUSA_HPP

