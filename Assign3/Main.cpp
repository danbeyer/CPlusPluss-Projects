/***********************************************************************************
** Program Filename: Main.cpp
** Author: Daniel Beyer
** Date: 05/04/16
** Description: Main method for Assignment 3.  This program is a class hierarchy as the basis for a fantasy combat game.
** It contains the creatures Medusa, Barbarian, Baba Yaga, Blue Men, and Harry Potter.  

** Input: Initial menu selection

** Output: Results of each combat round

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



int main()
{
	unsigned seed;
	seed = time(0);
	srand(seed);

	int exit = 0;
	int choice1 = 9;
	int choice2 = 9;
	Creature *creature1 = NULL;
	Creature *creature2 = NULL;
	cout << "Welcome to Assignment 3 - Fantasy Combat Game" << endl;

	while (exit != 6)
	{
		Menu();

		cout << "Select Creature 1:" << endl;
		cin >> choice1;

		cout << endl;
		while (choice1 < 1 || choice1 > 6 || !cin) // Input validation
		{
			cout << "Invalid selection, please select a number from 1 to 6" << endl;
			cin.clear();
			cin.ignore(100, '\n');
			cin >> choice1;
		}
		if (choice1 == 6)
		{
			exit = 6;
		}

		if (exit != 6)
		{
			cout << "Select Creature 2:" << endl;
			cin >> choice2;

			cout << endl;
			while (choice2 < 1 || choice2 > 6 || !cin) // Input validation
			{
				cout << "Invalid selection, please select a number from 1 to 6" << endl;
				cin.clear();
				cin.ignore(100, '\n');
				cin >> choice2;
			}
		}
		if (exit != 6)
		{
			if (choice1 == 1)
			{
				creature1 = new Barbarian;
			}
			if (choice1 == 2)
			{
				creature1 = new Medusa;
			}
			if (choice1 == 3)
			{
				creature1 = new BabaYaga;
			}
			if (choice1 == 4)
			{
				creature1 = new BlueMen;
			}
			if (choice1 == 5)
			{
				creature1 = new HarryPotter;
			}
			if (choice2 == 1)
			{
				creature2 = new Barbarian;
			}
			if (choice2 == 2)
			{
				creature2 = new Medusa;
			}
			if (choice2 == 3)
			{
				creature2 = new BabaYaga;
			}
			if (choice2 == 4)
			{
				creature2 = new BlueMen;
			}
			if (choice2 == 5)
			{
				creature2 = new HarryPotter;
			}

			cout << "Creature 1 is: " << creature1->getName() << endl;
			cout << "Creature 2 is: " << creature2->getName();
			cout << endl << endl;
			sleep(1000);


			while (creature1->getStrength() > 0 && creature2->getStrength() > 0)
			{
				/*********************************************************
				** Creature 1 attacks first here
				****************************************************/
				cout << creature2->getName() << " strength remaining is: " << creature2->getStrength() << endl;
				cout << creature1->getName() << " attacks " << creature2->getName() << " ...." << endl;

				int cr1attack = creature1->Attack();
				if (cr1attack == 100)
				{
					cout << "Medusa used GLARE, " << creature2->getName() << " is dead." << endl;
					creature2->setStrength(0);
					cout << endl;
					break;
				}

				else
				{
					cout << creature1->getName() << " rolled for " << cr1attack << " damage" << endl;

					cout << creature2->getName() << " defends against " << creature1->getName() << " ...." << endl;

					int cr2damage = creature2->Defend(cr1attack);
					cout << creature1->getName() << " did a total of " << cr2damage << " damage to " << creature2->getName() << endl;
					cout << endl;
					sleep(1500);

				}
				
				if (creature2->getStrength() <= 0)
				{
					cout << creature2->getName() << " has died." << endl;
					creature2->setStrength(0);
				}

				/**************************************************************
				** Creature 2 attacks next here
				***********************************************/
				else
				{
					cout << creature1->getName() << " strength remaining is: " << creature1->getStrength() << endl;
					cout << creature2->getName() << " attacks " << creature1->getName() << " ...." << endl;

					int cr2attack = creature2->Attack();
					if (cr2attack == 100)
					{
						cout << "Medusa used GLARE, " << creature1->getName() << " is dead." << endl;
						creature1->setStrength(0);
						cout << endl;
						break;
					}
					cout << creature2->getName() << " rolled for " << cr2attack << " damage" << endl;

					cout << creature1->getName() << " defends against " << creature2->getName() << " ...." << endl;

					int cr1damage = creature1->Defend(cr2attack);
					cout << creature2->getName() << " did a total of " << cr1damage << " damage to " << creature1->getName() << endl;
					cout << endl;

					if (creature1->getStrength() <= 0)
					{
						cout << creature1->getName() << " has died." << endl;
						creature1->setStrength(0);
						cout << endl;
					}

					cout << endl;
					cout << endl;
					sleep(1500);
				}
			}

		}

	}

	return 0;
}

