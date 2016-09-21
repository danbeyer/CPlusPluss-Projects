/***********************************************************************************
** Program Filename: Doodlebug.hpp
** Author: Daniel Beyer
** Date: 04/28/16
** Description: Class declaration file header for Doodlebug.cpp
***************************************************************************/
#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP
#include "Critter.hpp"

class Doodlebug : public Critter
{
private:
	int count;
	int starveMoves;

public:
	Doodlebug();
	virtual Doodlebug* Breed();
	virtual void Eat(Critter *critter);
	bool Starve();
	void IncrementStarveMoves();
	int getstarvemoves();


};

#endif // !DOODLEBUG_HPP
