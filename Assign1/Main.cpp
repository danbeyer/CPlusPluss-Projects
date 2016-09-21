/***********************************************************************************
** Program Filename: Main.cpp
** Author: Daniel Beyer
** Date: 03/29/16
** Description: Main method for Assignment 1.  This program is a simple implementation of Langton's ant.  The user
** is prompted to enter the dimension of a grid and the number of times they want the ant to move.  The user is also 
** asked if they would like the ant to be placed randomly on the grid, or they may enter their own coordinates.  The 
** ant starts facing a random direction to being with.  When hitting a white square (' '), the ant turns 90 degrees
** right, changes the square to black, and moves forward.  When hitting a black square ('#'), the ant turns 90 degrees 
** to the left, changes the square to white, and moves forward.

** Input: User specifies number of rows and columns for the grid and the number of moves for the ant to make.  The user
** then choses from a menu whether they want the ant placed randomly on the grid or whether they would like to specify 
** their own starting coordinates.

** Output: The array is printed showing the evolution of the moves of the ant every move.
***************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include "Grid.hpp"
#include "Ant.hpp"
using namespace std;

int main() {


	unsigned seed;
	seed = time(0);
	srand(seed);
	int rows, cols, numMoves; 
	

	/************************************************************************************************
	** Description: Here are the initial prompts to get the size of the grid and the number of moves to make.   
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


	cout << "Enter number of moves. Examples numbers are: " << endl
		<< "A few hundred to see a simple, near symmetric pattern (Simplicity)." << endl
		<< "Around 10,000 to see a pseudo-random pattern (Chaos)." << endl
		<< "Greater than 10,000 to recurring pattern (Emergent order)." << endl;
	cin >> numMoves;
	while (numMoves < 1 || !cin)
	{
		cout << "Please enter an integer greater than 0" << endl;
		cin.clear();
		cin.ignore();
		cin >> numMoves;
	}

	int x2 = rows + 2; // Here I am adding 2 to the size of the grid since I will add a border to the grid edges.
	int y2 = cols + 2;
	Grid g1(x2, y2);
	g1.fill(x2, y2);

	Ant c1(&g1);
	c1.setNumMoves(numMoves);

	c1.menu(&g1);

	c1.move(&g1);
	
	g1.remove(x2);

	cout << "Simulation completed!" << endl;
	return 0;
}

	

