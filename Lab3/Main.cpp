/***********************************************************************************
** Program Filename: Main.cpp
** Author: Daniel Beyer
** Date: 03/29/16
** Description: Main method for Lab2/ModB.  This program prompts the user for a an integer number of 
** rows and colums, the number of Critters to place on a grid, and the number of moves the Critters will make. 
** An array of pointers-to-Critter objects is created, and each Critter moves randomly each turn until the number
** of turns specified by the user has been reached.

** Input: The user specifies the number of rows and columns for the array, the number of Critters to place, and
** the number of moves to be made.

** Output: The array is printing every evolution(move) showing the movement of each Critter.
***************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Grid.hpp"
#include "Critter.hpp"
using namespace std;

int main() {


	unsigned seed;
	seed = time(NULL);
	srand(seed);
	int rows, cols, crits, moves;

	/************************************************************************************************
	** Description: Get x and y values for array grid from the user with input validation.
	*********************************************************************************************/
	cout << "Enter number of rows: ";
	cin >> rows;
	while (rows < 1 || !cin)
	{
		cout << "Please enter an integer greater than 0" << endl;
		cin.clear();
		cin.ignore();
		cin >> rows;
	}
	cout << "Enter number of columns: ";
	cin >> cols;
	while (cols < 1 || !cin)
	{
		cout << "Please enter an integer greater than 0" << endl;
		cin.clear();
		cin.ignore();
		cin >> cols;
	}
	cout << endl;

	cout << "Enter number of Critters: " << endl;
	cin >> crits;
	while (crits < 1 || crits>(rows*cols) || !cin)
	{
		cout << "Please enter an integer creater than 0 and less than the total number of cells on the grid:" << endl;
		cin.clear();
		cin.ignore();
		cin >> crits;
	}

	cout << "Please enter the number of moves you wish the critters to make:" << endl;
	cin >> moves;
	while (moves < 0 || !cin)
	{
		cout << "Please reenter an integer greater than 0." << endl;
		cin.clear();
		cin.ignore();
		cin >> moves;
	}


	int x2 = rows + 2; // Here I am adding 2 to the size of the grid since I will add a border to the grid edges.
	int y2 = cols + 2;
	Grid g1(x2, y2, moves);
	g1.fill(crits);
	g1.print();

	g1.start();

	

	return 0;

}

	

