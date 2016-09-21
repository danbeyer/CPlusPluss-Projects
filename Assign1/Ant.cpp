/***********************************************************************************
** Program Filename: Ant.cpp
** Author: Daniel Beyer
** Date: 03/29/16
** Description: Implementation file for class functions in Ant.hpp.
***************************************************************************/

#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include "Ant.hpp"
#include "Grid.hpp"

using namespace std;

/***************************************************************************
** Function: Ant
** Description: Ant object constructor that accepts a pointer to a Grid object as a parameter.  Constructor
** sets the initial coordinates of the ant to [0][0] on the Grid array and sets the initial direction to a random
** enum.

** Parameters: Pointer to Grid object.
** Pre-conditions: Valid Grid object.
** Post-conditions: int moves = 0, random direction, initial coordinates of ant are [0][0]. 
***************************************************************************/
Ant::Ant(Grid *g1)
{
	moves = 0;
	dir = static_cast<direction>(rand() % 3);
	rowCoord = 0;
	colCoord = 0;
	space = ' ';

}

/***************************************************************************
** Function: move
** Description: Accepts pointer to a Grid object as a parameter.  Uses a switch statement to determine the facing
** of the ant from the previous move.  In the switch statement, thew new direction is determined by what color the
** next array location is (' ' or '#').  A variable char space saves the value of the color of the array location
** to determine what color it should be changed to on the next moves.  

** Parameters: Pointer to Grid object.
** Pre-conditions: Valid Grid object.
** Post-conditions: rowCoord and colCoord values updated and sent to Grid object. Grid object prints.
***************************************************************************/

void Ant::move(Grid *g1)
{
	cout << "Initial Critter coordinates: " << rowCoord << ", "<< colCoord << endl;

	g1->print();

	while(moves < numMoves)
	{
		
		cout << string(10, '\n');
			switch (dir)
			{
			case N:
				if (g1->getColor(rowCoord -1, colCoord) == ' ')
				{
					dir = E;
					rowCoord = rowCoord -1;

					if (space == ' ')
					{
						g1->setColorBlack(rowCoord +1, colCoord);
					}

					else if (space == '#')
					{
						g1->setColorWhite(rowCoord + 1, colCoord);
					}
					g1->updateLocation(rowCoord, colCoord);
					space = ' ';
				}
				else if (g1->getColor(rowCoord - 1, colCoord) == '#')
				{
					dir = W;
					rowCoord = rowCoord - 1;

					if (space == ' ')
					{
						g1->setColorBlack(rowCoord + 1, colCoord);
					}

					else if (space == '#')
					{
						g1->setColorWhite(rowCoord + 1, colCoord);
					}

					space = '#';
					g1->updateLocation(rowCoord, colCoord);
				}
				else if (g1->getColor(rowCoord - 1, colCoord) == '+')
				{
					dir = S;

				}
				break;
			case E:
				if (g1->getColor(rowCoord, colCoord+1) == ' ')
				{
					dir = S;
					colCoord = colCoord + 1;

					if (space == ' ')
					{
						g1->setColorBlack(rowCoord, colCoord-1);
					}

					else if (space == '#')
					{
						g1->setColorWhite(rowCoord, colCoord-1);
					}

					space = ' ';
					g1->updateLocation(rowCoord, colCoord);
				}
				else if (g1->getColor(rowCoord, colCoord+1) == '#')
				{
					dir = N;
					colCoord = colCoord + 1;

					if (space == ' ')
					{
						g1->setColorBlack(rowCoord, colCoord-1);
					}

					else if (space == '#')
					{
						g1->setColorWhite(rowCoord, colCoord-1);
					}

					space = '#';
					g1->updateLocation(rowCoord, colCoord);
				}
				else if (g1->getColor(rowCoord, colCoord + 1) == '+')
				{
					dir = W;
				}
				break;
			case S:
				if (g1->getColor(rowCoord+1, colCoord) == ' ')
				{
					dir = W;
					rowCoord = rowCoord + 1;

					if (space == ' ')
					{
						g1->setColorBlack(rowCoord - 1, colCoord);
					}

					else if (space == '#')
					{
						g1->setColorWhite(rowCoord - 1, colCoord);
					}

					space = ' ';
					g1->updateLocation(rowCoord, colCoord);
				}
				else if (g1->getColor(rowCoord+1, colCoord) == '#')
				{
					dir = E;
					rowCoord = rowCoord + 1;

					if (space == ' ')
					{
						g1->setColorBlack(rowCoord - 1, colCoord);
					}

					else if (space == '#')
					{
						g1->setColorWhite(rowCoord - 1, colCoord);
					}

					space = '#';
					g1->updateLocation(rowCoord, colCoord);
				}
				else if (g1->getColor(rowCoord + 1, colCoord) == '+')
				{
					dir = N;

				}
				break;
			case W:
				if (g1->getColor(rowCoord, colCoord - 1) == ' ')
				{
					dir = N;
					colCoord = colCoord - 1;

					if (space == ' ')
					{
						g1->setColorBlack(rowCoord, colCoord+1);
					}

					else if (space == '#')
					{
						g1->setColorWhite(rowCoord, colCoord+1);
					}

					space = ' ';
					g1->updateLocation(rowCoord, colCoord);
				}
				else if (g1->getColor(rowCoord, colCoord - 1) == '#')
				{
					dir = S;
					colCoord = colCoord - 1;

					if (space == ' ')
					{
						g1->setColorBlack(rowCoord, colCoord+1);
					}

					else if (space == '#')
					{
						g1->setColorWhite(rowCoord, colCoord+1);
					}

					space = '#';
					g1->updateLocation(rowCoord, colCoord);
				}
				else if (g1->getColor(rowCoord, colCoord - 1) == '+')
				{
					dir = E;

				}
				break;
			}
			moves++;
			g1->print();
			sleep(100);



		}


	}

	/**************************************************************************************************
	Function: Setter functions.
	Description: Below are the setter functions for the ant variables.
	
	*******************************************************************************/

void Ant::setRowCoord(int x)
{
	rowCoord = x;
}

void Ant::setColCoord(int x)
{
	colCoord = x;
}

void Ant::setNumMoves(int x)
{
	numMoves = x;
}

/********************************************************************************************
** Function: menu
** Description: This is the main menu to determine the starting location of the ant, with input validation.

** Parameters: Pointer to grid object
** Pre-conditions: valid grid object
** Post-conditions: Ant placed on grid.
*****************************************************************************************/

void Ant::menu(Grid *g1)
{
	char random;
	int initRowCoord, initColCoord;
	cout << "Would you like the ant to start at random location?" << endl
		<< "	Y = Random location " << endl
		<< "	N = I will input starting coordinates" << endl;
	cin >> random;

	random = toupper(random);
	while (random != 'Y' && random != 'N')
	{
		cout << "Invalid input, please input Y/y or N/n." << endl;
		cin >> random;
		random = toupper(random);
	}

	switch (random)
	{
	case 'Y':	if (random == 'Y')
	{
		setRowCoord(rand() % (g1->getRows() - 2) + 1);
		setColCoord(rand() % (g1->getCols() - 2) + 1);
	}
				break;
	case 'N': 	if (random == 'N')
	{
		cout << "Please enter initial row coordinates for ant:" << endl;
		cin >> initRowCoord;
		while (initRowCoord < 0 || initRowCoord > g1->getRows() || !cin)
		{
			cout << "Please enter an integer greater than 0 and less than the number of rows in the grid." << endl;
			cin.clear();
			cin.ignore();
			cin >> initRowCoord;
		}

		cout << "Please enter initial column coordinates for ant:" << endl;
		cin >> initColCoord;
		while (initColCoord < 0 || initColCoord > g1->getCols() || !cin)
		{
			cout << "Please enter an integer greater than 0 and less than the number of columns in the grid." << endl;
			cin.clear();
			cin.ignore();
			cin >> initColCoord;
		}

		setRowCoord(initRowCoord);
		setColCoord(initColCoord);
	}
				break;
	}
	cout << endl;
}

/**********************************************************************************************************
** Function: sleep function
** Description: Pauses the program for a specified number of milliseconds.

** Parameters: int milliseconds
** Pre-conditions: #include<ctime>
** Post-conditions: Program paused.
********************************************************************************************/

void Ant::sleep(int milliseconds)
{
	clock_t time;
	time = clock() + milliseconds * CLOCKS_PER_SEC / 1000;
	while (clock() < time)
	{

	}
}
