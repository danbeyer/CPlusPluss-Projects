/***********************************************************************************
** Program Filename: Critter.cpp
** Author: Daniel Beyer
** Date: 03/29/16
** Description: Implementation file for class functions in Critter.hpp.
***************************************************************************/

#include<iostream>
#include<cstdlib>
#include<ctime>
#include "Critter.hpp"
#include "Grid.hpp"

using namespace std;

/***************************************************************************
** Function: Critter
** Description: Critter object construction that accepts a pointer to a Grid object as a parameter.  Constructor
** sets the initial coordinates of the "C" critter to random coordinates on the Grid array, and passes the coordinates
** to the Grid object via the updateLocation() function.

** Parameters: Pointer to Grid object.
** Pre-conditions: Valid Grid object.
** Post-conditions: int moves = 0, initial critter coordinates on the grid set randomly and sent to grid object. 
***************************************************************************/
Critter::Critter(Grid *g1)
{
	moves = 0;
	rowCoord = rand()% (g1->getRows()-2)+1;
	colCoord = rand() % (g1->getCols()-2)+1;
	g1->updateLocation(rowCoord, colCoord);
}

/***************************************************************************
** Function: move
** Description: Accepts pointer to a Grid object as a parameter.  Prints the initial Grid array with initial position
** of Critter "C".  Generates a random number from 0-3 to determine which direction the Critter will go on the board.
** Those coordinates are passed to the grid via updateLocation(), where a check is made to see if that position is off
** the grid or not.  updateLocation() will return bool false if it is off the grid, the while loop will end.

** Parameters: Pointer to Grid object.
** Pre-conditions: Valid Grid object.
** Post-conditions: rowCoord and colCoord values updated and sent to Grid object. Moves++. Grid object prints.
***************************************************************************/

void Critter::move(Grid *g1)
{
	cout << "Initial Critter coordinates: " << rowCoord << ", "<< colCoord << endl;
	g1->print();
	while(g1->updateLocation(rowCoord, colCoord))
	{
	int direction = rand() % 3;
	
	if (direction == 0)
	{
		rowCoord = rowCoord - 1;
		g1->updateLocation(rowCoord, colCoord);
		g1->gridClear((rowCoord + 1), colCoord);
	}
	else if (direction == 1)
	{
		rowCoord = rowCoord + 1;
		g1->updateLocation(rowCoord, colCoord);
		g1->gridClear((rowCoord - 1), colCoord);
	}
	else if (direction == 2)
	{
		colCoord = colCoord - 1;
		g1->updateLocation(rowCoord, colCoord);
		g1->gridClear(rowCoord, (colCoord + 1));
	}
	else if (direction == 3)
	{
		colCoord = colCoord + 1;
		g1->updateLocation(rowCoord, colCoord);
		g1->gridClear(rowCoord, (colCoord - 1));
	}
	g1->print();
	moves++;
		}
}

/***************************************************************************
** Function: Get functions
** Description: Get functions for the rowCoord and colCoord values.

** Parameters: None.
** Pre-conditions: None.
** Post-conditions: None.
***************************************************************************/

int Critter::getRowCoord()
{
	return rowCoord;
}

int Critter::getColCoord()
{
	return colCoord;
}

/***************************************************************************
** Function: Get function for move
** Description: Get function for int move to display moves at the end of the program.

** Parameters: None.
** Pre-conditions: None.
** Post-conditions: None.
***************************************************************************/

int Critter::getMoves()
{
	return moves;
}