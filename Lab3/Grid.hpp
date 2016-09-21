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


class Grid
{
private:

	Ant ***arr;
	int numRows;
	int numCols;
	int moves;
	int numCrits;

public:


	Grid(int rows, int cols, int numMoves);
	~Grid();
	int getRows();
	int getCols();
	void fill(int crits);
	void print();
	void placeCrit();
	void placeBorder();
	void start();
	void sleep(int milliseconds);

};
#endif