/***********************************************************************************
** Program Filename: HelperFunctions.cpp
** Author: Daniel Beyer
** Date: 05/04/16
** Description: Implementation file for class functions in HelperFunctions.hpp.
***************************************************************************/
#include<iostream>
#include<string>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include "HelperFunctions.hpp"
using namespace std;

/*********************************************************************
** Function: Menu()
** Description: Menu Function
*******************************************************************/
void Menu()
{
	cout << "Select 2 types of Creatures to do battle from the list below:" << endl;
	cout << "1: Barbarian" << endl;
	cout << "2: Medusa" << endl;
	cout << "3: Baba Yaga" << endl;
	cout << "4. Blue Men" << endl;
	cout << "5. Harry Potter" << endl;
	cout << "6: Exit" << endl;
	cout << endl << endl;
}

/**********************************************************************************************************
** Function: sleep function
** Description: Pauses the program for a specified number of milliseconds.

** Parameters: int milliseconds
** Pre-conditions: #include<ctime>
** Post-conditions: Program paused.
********************************************************************************************/

void sleep(int milliseconds)
{
	clock_t time;
	time = clock() + milliseconds * CLOCKS_PER_SEC / 1000;
	while (clock() < time)
	{

	}
}