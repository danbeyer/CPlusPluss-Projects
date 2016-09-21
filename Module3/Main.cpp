/***********************************************************************************
** Program Filename: Main.cpp
** Author: Daniel Beyer
** Date: 05/27/16
** Description: Main method for Module 3.  This program simulates a simple traffic intersection using an STL Queue.

** Input: The user specifies the number of iterations to perform.
** Output: Displays the total number of cars arriving and departing in each lane each cycle of the light. At the end 
** of the simulation the average wait time for each direction is displayed.
***************************************************************************/
#include<iostream>
#include<string>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<queue>
#include "State.hpp"
#include "HelperFunctions.hpp"


using namespace std;

int main()
{
	unsigned seed;
	seed = time(0);
	srand(seed);

	State state;
	queue<int> eQueue;
	queue<int> wQueue;
	queue<int> nQueue;
	queue<int> sQueue;

	state.add('G', 'R', 'E', 'W');
	state.add('Y', 'R', 'E', 'W');
	state.add('R', 'G', 'N', 'S');
	state.add('R', 'Y', 'N', 'S');

	

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

	for (int i = 1; i <= count;) // Loops through nodes to perform functions, checks to see if it has reached the beginning with an if statement
	{
		currentstate->nrOfVehiclesArrive(eQueue, wQueue, nQueue, sQueue, i);
		cout << "East/West light is: " << currentstate->getEW() << endl;
		cout << "North/South light is: " << currentstate->getNS() << endl;
		currentstate->nrOfVehiclesDepart(eQueue, wQueue, nQueue, sQueue, i);
		currentstate = currentstate->getnextState();
		if (currentstate->getnextState() == state.getHead())
		{
			i++;
			//sleep(1500);
		}
		
	}

	/******************************************
	** Here I loop through the nodes looking for a totalDepart value that is not 0, as this has to be the
	** the totalDepart value for the given lane I am looking for.  Then the average for each lane is calculated by
	** taking the sum of all the wait times for every car that departed that direction and dividing that by the total number of cars
	** that departed.
	****************************************************/
	while (currentstate->gettotalDepartE() == 0)
	{
		currentstate = currentstate->getnextState();
	}
	
	cout << "Total Eastbound departs = " << currentstate->gettotalDepartE() << endl;
	cout << "Total Eastbound arrivals = " << currentstate->gettotalArrivalE() << endl;
	cout << "Total Eastbound wait time: " << currentstate->gettotalwaitE() << endl;
	cout << "Average wait time for Eastbound cars = " << currentstate->gettotalwaitE() / currentstate->gettotalDepartE() << endl;
	while (currentstate->gettotalDepartW() == 0)
	{
		currentstate = currentstate->getnextState();
	}

	cout << "Total Westbound departs = " << currentstate->gettotalDepartW() << endl;
	cout << "Total Westbound arrivals = " << currentstate->gettotalArrivalW() << endl;
	cout << "Total Westbound wait time: " << currentstate->gettotalwaitW() << endl;
	cout << "Average wait time for Westbound cars = " << currentstate->gettotalwaitW()/currentstate->gettotalDepartW()  << endl;
	while (currentstate->gettotalDepartN() == 0)
	{
		currentstate = currentstate->getnextState();
	}
	cout << "Total Northbound departs = " << currentstate->gettotalDepartN() << endl;
	cout << "Total Northbound arrivals = " << currentstate->gettotalArrivalN() << endl;
	cout << "Total Northbound wait time: " << currentstate->gettotalwaitN() << endl;
	cout << "Average wait time for Northbound cars = " << currentstate->gettotalwaitN()/currentstate->gettotalDepartN() << endl;
	while (currentstate->gettotalDepartS() == 0)
	{
		currentstate = currentstate->getnextState();
	}
	cout << "Total Southbound departs = " << currentstate->gettotalDepartS() << endl;
	cout << "Total Southbound arrivals = " << currentstate->gettotalArrivalS() << endl;
	cout << "Total Southbound wait time: " << currentstate->gettotalwaitS() << endl;
	cout << "Average wait time for Southbound cars = " << currentstate->gettotalwaitS()/currentstate->gettotalDepartS() << endl;


	return 0;
}

