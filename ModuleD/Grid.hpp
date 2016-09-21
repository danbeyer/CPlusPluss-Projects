/***********************************************************************************
** Program Filename: Grid.hpp
** Author: Daniel Beyer
** Date: 03/29/16
** Description: Class declaration file header for Grid.cpp
***************************************************************************/
#ifndef GRID_HPP
#define GRID_HPP
#include "Critter.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"


class Grid
{
private:

	Critter ***arr;
	int numRows;
	int numCols;
	int moves;
	int numCrits;

public:


	Grid(int rows, int cols, int numMoves);
	~Grid();
	int getRows();
	int getCols();
	void fillCrits(int ants, int doodlebugs);
	void print();
	void placeAnts();
	void placeDoodlebugs();
	void placeBorder();
	void start();
	void sleep(int milliseconds);

};
#endif