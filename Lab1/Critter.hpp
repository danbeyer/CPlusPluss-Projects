/***********************************************************************************
** Program Filename: Critter.hpp
** Author: Daniel Beyer
** Date: 03/29/16
** Description: Class declaration file header for Critter.cpp.
***************************************************************************/

#ifndef CRITTER_HPP
#define CRITTER_HPP
#include "Grid.hpp"

class Critter
{
private:
	
	int moves;
	int rowCoord;
	int colCoord;
public:
	Critter(Grid *g1);
	void move(Grid *g1);
	int getRowCoord();
	int getColCoord();
	int getMoves();

};

#endif
