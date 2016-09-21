/***********************************************************************************
** Program Filename: Main.cpp
** Author: Daniel Beyer
** Date: 03/29/16
** Description: Main method for Lab1/ModA.  This program prompts the user for a an integer number of 
** rows and colums and the builds a grid and randomly places a Critter ("C") in the grid.  The Critter
** moves one of 4 directions randomly until leaving the grid, at which point a message displays the number of 
** moves it took to leave the grid.
***************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Grid.hpp"
#include "Critter.hpp"
using namespace std;

int main() {


	unsigned seed;
	seed = time(0);
	srand(seed);
	int rows, cols;

	/************************************************************************************************
	** Description: Get x and y values for array grid from the user with input validation.
	*********************************************************************************************/
	cout << "Enter number of rows: ";
	cin >> rows;
	while (rows < 1)
	{
		cout << "Please enter an integer greater than 0" << endl;
		cin >> rows;
	}
	cout << "Enter number of columns: ";
	cin >> cols;
	while (cols < 1)
	{
		cout << "Please enter an integer greater than 0" << endl;
		cin >> cols;
	}
	cout << endl;



	int x2 = rows + 2; // Here I am adding 2 to the size of the grid since I will add a border to the grid edges.
	int y2 = cols + 2;
	Grid g1(x2, y2);
	g1.fill(x2, y2);

	Critter c1(&g1);

	c1.move(&g1);
	cout << "It took " << c1.getMoves() << " moves to squash the ant." << endl;
	g1.remove(x2);
	return 0;
}

	

