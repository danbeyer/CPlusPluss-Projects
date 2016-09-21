/***********************************************************************************
** Program Filename: Ant.hpp
** Author: Daniel Beyer
** Date: 03/29/16
** Description: Class declaration file header for Critter.cpp.
***************************************************************************/

#ifndef CRITTER_HPP
#define CRITTER_HPP
#include "Grid.hpp"

class Ant
{
private:
	
	enum direction {N, S, E, W};
	direction dir;
	int moves;
	int numMoves;
	int rowCoord;
	int colCoord;
	char space;
public:
	Ant(Grid *g1);
	void move(Grid *g1);
	void menu(Grid *g1);
	void setRowCoord(int x);
	void setColCoord(int x);
	void setNumMoves(int x);
	void sleep(int milliseconds);

};

#endif
