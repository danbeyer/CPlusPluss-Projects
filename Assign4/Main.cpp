/***********************************************************************************
** Program Filename: Main.cpp
** Author: Daniel Beyer
** Date: 05/04/16
** Description: Main method for Assignment 4.  
** This program is a creature tournament where each player choses their lineup of creatures.
** It contains the creatures Medusa, Barbarian, Baba Yaga, Blue Men, and Harry Potter.  

** Input: Initial menu selection to chose size of teams and each lineup

** Output: Results of each combat round. At the end of the tournament, displays first, second, and third place finishers.
** Also displays which side scored the most points and an option to view the total order of creatures.

***************************************************************************/
#include<iostream>
#include<string>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include "Creature.hpp"
#include "Barbarian.hpp"
#include "Medusa.hpp"
#include "BabaYaga.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "HelperFunctions.hpp"
#include "Game.hpp"
#include "Stack.hpp"
#include "Queue.hpp"




int main()
{
	unsigned seed;
	seed = time(0);
	srand(seed);
	int numCr;

	cout << "Welcome to Assignment 4 -- Creature Tournament" << endl;
	cout << "Enter the number of creatures each team will have in the tournament: " << endl;
	cin >> numCr;
	while (numCr<1 ||!cin)
	{
		cout << "Invalid selection, please select a number greater than 1" << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cin >> numCr;
	}

	Game game;
	game.setPlayer1(numCr);
	game.setPlayer2(numCr);
	game.Combat();
	game.results();

	

	
	return 0;
	
}


