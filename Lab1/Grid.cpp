/***********************************************************************************
** Program Filename: Grid.cpp
** Author: Daniel Beyer
** Date: 03/29/16
** Description: Implementation file for class functions in Grid.hpp.
***************************************************************************/

#include<iostream>
#include "Grid.hpp"

using namespace std;



/****************************************************************************
** Function: Grid
** Description: Constructor that initializes the grid.  Accepts as parameters the rows and cols values entered by the user.

** Parameters: int rows, int cols
** Pre-conditions: rows and cols > 0
** Post-conditions: New char array created.
***************************************************************/

Grid::Grid(int rows, int cols)
{
	numRows = rows;
	numCols = cols;
	arr = new char*[rows];
	for (int i = 0; i < rows; i++)
		arr[i] = new char[cols];

}


/********************************************************************************
** Function: Fill
** Description: Fills the array with " " and fills the edges with "+" to create a border.

** Parameters: int rows, int cols.
** Pre-conditions: None.
** Post-conditions: Array in Grid object filled with " " with a border of "+".
******************************************************************************/

void Grid::fill(int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = ' ';
		}
	}
	for (int i = 0; i < cols; i++)
	{
		arr[0][i] = '+';
	}
	for (int i = 0; i < cols; i++)
	{
		arr[rows-1][i] = '+';
	}
	for (int i = 0; i < rows; i++)
	{
		arr[i][0] = '+';
	}
	for (int i = 0; i < rows; i++)
	{
		arr[i][cols - 1] = '+';
	}
}

/********************************************************************************************************
** Function: print
** Description: Prints the array after every move of the Critter.

** Parameters: None.
** Pre-conditions: None.
** Post-conditions: None.
***********************************************************************************************/

void Grid::print()
{
	int rows = numRows;
	int cols = numCols;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

/******************************************************************************************************
** Function: Remove
** Description: Deletes the array and frees up the allocated memory.

** Parameters: None.
** Pre-conditions: None.
** Post-conditions: None.
************************************************************************************************/

void Grid::remove(int x)
{
	for (int i = 0; i < x; i++)
		delete(arr[i]);
	delete(arr);
}


int Grid::getRows()
{
	return numRows;
}

int Grid::getCols()
{
	return numCols;
}

/**********************************************************************************************************
** Function: updateLocation
** Description: rowC and colC are passed to updateLocation from the Critter object to move the "C" on the Grid object
** array.  The function is a bool function, it returns false if the array position is inhabited by a "+" indicating 
** the Critter is outside the edge of the grid.  Otherwise, "C" replaces the " " of the position on the grid and the function
** returns true and the while loop in Critter continues.

** Parameters: int rowC, int colC
** Pre-conditions: None.
** Post-conditions: Array in Grid object updated, if coordinates passed by parameters were occupied by "+", bool false
** returned.
********************************************************************************************/

bool Grid::updateLocation(int rowC, int colC)
{

	if (arr[rowC][colC] == '+')
	{
		return false;
	}
	else
	{
		arr[rowC][colC] = 'C';
		return true;
	}
}

/**********************************************************************************************************
** Function: gridClear
** Description: Clears previous array coordinates, returns char value of previous location is " ".

** Parameters: int prevRow, int prevCol
** Pre-conditions: None.
** Post-conditions: Array in Grid object updated
********************************************************************************************/

void Grid::gridClear(int prevRow, int prevCol)
{
	arr[prevRow][prevCol] = ' ';
}
