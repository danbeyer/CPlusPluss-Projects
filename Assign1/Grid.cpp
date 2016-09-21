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
** array.  

** Parameters: int rowC, int colC
** Pre-conditions: None.
** Post-conditions: Array in Grid object updated.
********************************************************************************************/

void Grid::updateLocation(int rowC, int colC)
{

		arr[rowC][colC] = '*';
		
}

/**********************************************************************************************************
** Function: gridClear
** Description: Clears previous array coordinates, returns char value of previous location is " ".

** Parameters: int prevRow, int prevCol
** Pre-conditions: None.
** Post-conditions: Array in Grid object updated
********************************************************************************************/



char Grid::getColor(int row, int col)
{
	char color;
	color = arr[row][col];
	return color;
}

/**********************************************************************************************************
** Function: setColor functions
** Description: Sets the color of the specified array cell to white (" ") or black ("#").

** Parameters: int row, int col
** Pre-conditions: None.
** Post-conditions: Array in Grid object updated
********************************************************************************************/

void Grid::setColorWhite(int row, int col)
{
	arr[row][col] = ' ';
}

void Grid::setColorBlack(int row, int col)
{
	arr[row][col] = '#';
}

