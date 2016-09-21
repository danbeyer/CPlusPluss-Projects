/***********************************************************************************
** Program Filename: Critter.cpp
** Author: Daniel Beyer
** Date: 03/29/16
** Description: Implementation file for class functions in Critter.hpp.
***************************************************************************/

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include "Critter.hpp"
//#include "Grid.hpp"

using namespace std;

/***************************************************************************
** Function: Critter
** Description: Critter object default constructor. Sets initial coordinate values to 0, and sets moved variable to
** "n".

** Parameters: None
** Pre-conditions: None
** Post-conditions: Critter defaults to not moved. 
***************************************************************************/
Critter::Critter()
{
	
	rowCoord = 0;
	colCoord = 0;
	moved = 'n';
	type = 'C';
	
}

/***************************************************************************
** Function: move
** Description: Returns an int corresponding to a random direction of 0,1,2,3.  Used to determine which direction
** the critter will move on the grid.

** Parameters: None
** Pre-conditions: None
** Post-conditions: Returns a random int.
***************************************************************************/

int Critter::move()
{
	int direction = rand() % 4;
	return direction;
	
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

/**************************************************************************
** Functions: Below are the setter functions
** Descriptions: These functions set the type of critter. The options are a border critter, blank critter, or 
** critter critter.  This info is saved in the char type variable to be retrieved by the Grid class to determine
** which type of critter is inhabiting a designated cell.

** Parameters: setCritter has int rows and int cols parameters and setMoved has a char parameter
** Pre-Conditions: None
** Post-Conditions: char type and char moved variables are altered accordingly.
*********************************************************/

void Critter::setBorder()
{
	type = '+';
}

void Critter::setBlank()
{
	type = ' ';
}

void Critter::setCritterCoord(int rows, int cols)
{
	//type = 'C';
	rowCoord = rows;
	colCoord = cols;
}

void Critter::setMoved(char x)
{
	moved = x;
}

/*****************************************************************************************
** Functions: Getter functions
** Descriptions: These are getter functions to retrieve defining information about each critter object.  They
** return the char type of critter and the char moved, indicating if the critter has moved this turn or not.

** No Parameters, Pre-Conditions, or Post-Conditions
**********************************************************************************************/

char Critter::getCharType()
{
	return type;
}

char Critter::getMoved()
{
	return moved;
}

