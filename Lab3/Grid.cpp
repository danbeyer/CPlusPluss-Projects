/***********************************************************************************
** Program Filename: Grid.cpp
** Author: Daniel Beyer
** Date: 03/29/16
** Description: Implementation file for class functions in Grid.hpp.
***************************************************************************/

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include "Grid.hpp"

using namespace std;



/****************************************************************************
** Function: Grid
** Description: Constructor that initializes the grid.  Accepts as parameters the rows and cols values entered by the user.
** Also accepts the number of moves to make and stores that information.  The array is initialized to NULL.

** Parameters: int rows, int cols, numMoves
** Pre-conditions: rows and cols > 0
** Post-conditions: New pointer-to-Critter array created.
***************************************************************/


Grid::Grid(int rows, int cols, int numMoves)
{
	moves = numMoves;
	numRows = rows;
	numCols = cols;
	arr = new Ant**[rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new Ant*[cols];
		for (int x = 0; x < cols; x++)
		{
			
			arr[i][x] = NULL;

		}
	}
}


/********************************************************************************
** Function: Fill
** Description: Fills the array with new critters and initially sets all critters to "blank" critters.
** Then critter critters are placed.

** Parameters: int rows, int cols, int crits
** Pre-conditions: None.
** Post-conditions: Array in Grid object filled with critters.
******************************************************************************/

void Grid::fill(int crits){
	numCrits = crits;
	placeBorder();

	for (int i = 0; i < crits; i++)
	{
		placeCrit();
	}
	
	
}

/********************************************************************************************************
** Function: print
** Description: Prints the array after every move of the critters.

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
			if (arr[i][j] != NULL)
			{
				cout << arr[i][j]->getCharType();
			}
			if (arr[i][j] == NULL)
			{
				cout << " ";
			}
		}
		cout << endl;
	}

}


int Grid::getRows()
{
	return numRows;
}

int Grid::getCols()
{
	return numCols;
}


/**********************************************************************************
** Function: placeCrit
** Description: Places critter object randomly on the grid and assigns it the critter type.
** If the space is already taken, new coordinates are generated.

** Parameters: None
** Pre-conditions: None
** Post-conditions: Critter object placed on the array.
***********************************************************************/


void Grid::placeCrit()
{
	bool NotFree = true;
	while (NotFree == true)
	{
		int x = rand() % (numRows - 2) + 1;
		int y = rand() % (numCols - 2) + 1;
		if (arr[x][y] == NULL)
		{
			arr[x][y] = new Ant;
			arr[x][y]->setCritterCoord(x, y);
			NotFree = false;
		}
		else
		{
			int x = rand() % (numRows - 2) + 1;
			int y = rand() % (numCols - 2) + 1;
			if (arr[x][y] != NULL)
				NotFree = true;
		}
	}
}

/**********************************************************************************
** Function: placeBorder
** Description: Places new critters along the border of the grid and ssigns it the border critter type.

** Parameters: None
** Pre-conditions: None
** Post-conditions: Critter objects placed on the array.
***********************************************************************/

void Grid::placeBorder()
{

	for (int i = 0; i < numCols; i++)
	{
		arr[0][i] = new Ant;
		arr[0][i]->setBorder();
	}


	for (int i = 0; i < numCols; i++)
	{
		arr[numRows-1][i] = new Ant;
		arr[numRows-1][i]->setBorder();

	}
	for (int i = 0; i < numRows; i++)
	{
		arr[i][0] = new Ant;
		arr[i][0]->setBorder();
	}
	for (int i = 0; i < numRows; i++)
	{
		arr[i][numCols - 1] = new Ant;
		arr[i][numCols - 1]->setBorder();
	}
}

/**********************************************************************************************
** Function: start
** Description: This is the primary simulation function.  The program cycles through the array looking for 
** ant objects that have not moved yet.  Once found, a random direction is generated and 
** the program checks to see if there are any objects in the adjacent cell to be occupied by the current
** object.  If there is not, the current ant is moved to the cell and designated as moved, and the old cell is
** switched back to a blank NULL cell.  At the beginning of the while loop, the array is searched for open spaces.
** If there are no open spaces, then the array is filled with Ants and the simulation ends.

** Parameters: None
** Pre-conditions: None
** Post-conditions: while loop continues for the designated number of moves as specified by the user or until 
** board is full.
*****************************/

void Grid::start()
{

	int l = 0;
	while (l < moves)
	{
		for (int i = 1; i < numRows - 1; i++)
		{
			for (int j = 1; j < numCols - 1; j++)
			{
				if (arr[i][j] != NULL)
				{
					numCrits++;
				}
			}

		}
		if (numCrits == ((numRows - 2) * (numCols - 2)))
		{
			cout << "Board full!" << endl;
			break;
		}
		
		cout << string(20, '\n');
		for (int i = 1; i < numRows - 1; i++)
		{
			for (int j = 1; j < numCols - 1; j++)
			{

				if (arr[i][j] != NULL && arr[i][j]->getMoved() == 'n')
				{
					Ant *currAnt = arr[i][j];
					int dir = arr[i][j]->move();
					if (dir == 0)
					{
						if (arr[i - 1][j] == NULL)
						{

							arr[i - 1][j] = currAnt;
							arr[i - 1][j]->setCritterCoord((i - 1), j);
							arr[i - 1][j]->setMoved('y');
							arr[i][j] = currAnt->Breed();
						}
					}
					else if (dir == 1)
					{
						if (arr[i + 1][j] == NULL)
						{

							arr[i + 1][j] = currAnt;
							arr[i + 1][j]->setCritterCoord((i + 1), j);
							arr[i + 1][j]->setMoved('y');
							arr[i][j] = currAnt->Breed();;
						}
					}
					else if (dir == 2)
					{
						if (arr[i][j - 1] == NULL)
						{

							arr[i][j - 1] = currAnt;
							arr[i][j - 1]->setCritterCoord((j - 1), j);
							arr[i][j - 1]->setMoved('y');
							arr[i][j] = currAnt->Breed();;
						}
					}
					else if (dir == 3)
					{
						if (arr[i][j + 1] == NULL)
						{

							arr[i][j + 1] = currAnt;
							arr[i][j + 1]->setCritterCoord((j + 1), j);
							arr[i][j + 1]->setMoved('y');
							arr[i][j] = currAnt->Breed();;
						}
					}

				}
				else if (arr[i][j] != NULL && arr[i][j]->getMoved() == 'y')
				{
					arr[i][j]->setMoved('n');
				}

			}
		}
		l++;
		print();
		sleep(100);
		numCrits = 0;

	}
	cout << "All moves complete, simulation complete!" << endl;
}

/**********************************************************************************************************
** Function: sleep function
** Description: Pauses the program for a specified number of milliseconds.

** Parameters: int milliseconds
** Pre-conditions: #include<ctime>
** Post-conditions: Program paused.
********************************************************************************************/

void Grid::sleep(int milliseconds)
{
	clock_t time;
	time = clock() + milliseconds * CLOCKS_PER_SEC / 1000;
	while (clock() < time)
	{

	}
}

/*****************************************************************************
** Function: Grid destructor
** Description: Grid destructor
******************************************************************************/

Grid::~Grid()
{
	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < numCols; j++) 
		{
			delete arr[i][j];
		}
		delete arr[i];
	}
		
		delete[] arr;
		
	}






