/***********************************************************************************
** Program Filename: Ant.hpp
** Author: Daniel Beyer
** Date: 04-13-2016
** Description: Class declaration file header for Ant.cpp.
***************************************************************************/

#ifndef ANT_HPP
#define ANT_HPP
#include "Critter.hpp"


class Ant : public Critter
{
private:
	int count;

public:
	Ant();
	virtual Ant* Breed();
	virtual void Eat(Critter *critter);

};


#endif
