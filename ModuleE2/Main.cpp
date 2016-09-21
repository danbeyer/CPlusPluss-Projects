/***********************************************************************************
** Program Filename: Main.cpp
** Author: Daniel Beyer
** Date: 03/29/16
** Description: Main method for Module E.  This program simulates a simple traffic intersection.

** Input: The user specifies the number of iterations to perform.
** Output: Displays the total number of cars arriving and departing in each lane each cycle of the light.
***************************************************************************/
#include<iostream>
#include<string>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include "State.hpp"
#include "HelperFunctions.hpp"

using namespace std;

int main()
{
	unsigned seed;
	seed = time(0);
	srand(seed);

	State state;
	state.add('G', 'R', 'E', 'W');
	state.add('Y', 'R', 'E', 'W');
	state.add('R', 'G', 'N', 'S');
	state.add('R', 'Y', 'N', 'S');

	state.display();

	State *currentstate = state.getHead();

	int count;
	cout << "How many iterations to run?" << endl;
	cin >> count;
	while (count < 1 || !cin)
	{
		cout << "Please enter an integer greater than 0" << endl;
		cin.clear();
		cin.ignore();
		cin >> count;
	}

	for (int i = 0; i < count;) // Loops through nodes to perform functions, checks to see if it has reached the beginning with an if statement
	{
		currentstate->nrOfVehiclesArrive();
		cout << "East/West light is: " << currentstate->getEW() << endl;
		cout << "North/South light is: " << currentstate->getNS() << endl;
		currentstate->nrOfVehiclesDepart();
		currentstate = currentstate->nextState;
		if (currentstate->nextState == state.getHead())
		{
			i++;
			sleep(1500);
		}
		
	}

	/******************************************
	** Here I loop through the nodes looking for a totalDepart value that is not 0, as this has to be the
	** the totalDepart value for the given lane I am looking for.
	****************************************************/
	while (currentstate->totalDepartE == 0)
	{
		currentstate = currentstate->nextState;
	}
	
	cout << "Total Eastbound departs = " << currentstate->totalDepartE << endl;
	cout << "Total Eastbound arrivals = " << currentstate->totalArrivalE << endl;
	cout << "Average wait time for Eastbound cars = " << currentstate->totalDepartE / count << endl;
	while (currentstate->totalDepartW == 0)
	{
		currentstate = currentstate->nextState;
	}

	cout << "Total Westbound departs = " << currentstate->totalDepartW << endl;
	cout << "Total Westbound arrivals = " << currentstate->totalArrivalW << endl;
	cout << "Average wait time for Westbound cars = " << currentstate->totalDepartW / count << endl;
	while (currentstate->totalDepartN == 0)
	{
		currentstate = currentstate->nextState;
	}
	cout << "Total Northbound departs = " << currentstate->totalDepartN << endl;
	cout << "Total Northbound arrivals = " << currentstate->totalArrivalN << endl;
	cout << "Average wait time for Northbound cars = " << currentstate->totalDepartN / count << endl;
	while (currentstate->totalDepartS == 0)
	{
		currentstate = currentstate->nextState;
	}
	cout << "Total Southbound departs = " << currentstate->totalDepartS << endl;
	cout << "Total Southbound arrivals = " << currentstate->totalArrivalS << endl;
	cout << "Average wait time for Southbound cars = " << currentstate->totalDepartS / count << endl;

	return 0;
}

