/***********************************************************************************
** Program Filename: Game.cpp
** Author: Daniel Beyer
** Date: 05/04/16
** Description: Implementation file for class functions in Game.hpp.
***************************************************************************/
#include<iostream>
#include<string>
#include "Game.hpp"
#include "BabaYaga.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
#include "HelperFunctions.hpp"

using std::cout;
using std::cin;
using std::endl;

Game::Game() // default constructor
{
	creature1 = NULL;
	creature2 = NULL;
	creature = NULL;
	player1pts = 0;
	player2pts = 0;
}

/**********************************************************
** Function: setPlayer1()
** Description: This function allows the user to select the creatures to participate in the tournament and to give
** them unique names.  Creatures are added to the player queue.

** Parameters: int
** Pre-Conditions: None
** Post-Conditions: Creatures added to player queue.
****************************************************************/
void Game::setPlayer1(int numCreatures)
{
	int i = 0;
	player1.setSize(numCreatures);
	cout << "Player 1, select the creatures for your team: " << endl;
	while (i < numCreatures)
	{
		int choice1;
		string tempname;
		Menu();
		cin >> choice1;
		cout << endl;
		while (choice1 < 1 || choice1 > 5 || !cin) // Input validation
		{
			cout << "Invalid selection, please select a number from 1 to 6" << endl;
			cin.clear();
			cin.ignore(100, '\n');
			cin >> choice1;
		}

		cout << "Enter a custom name for your creature: " << endl;
		cin >> tempname;
		cout << endl;
		if (choice1 == 1)
		{
			creature = new Barbarian(tempname);
		}
		else if (choice1 == 2)
		{
			creature = new Medusa(tempname);
		}
		else if (choice1 == 3)
		{
			creature = new BabaYaga(tempname);
		}
		else if (choice1 == 4)
		{
			creature = new BlueMen(tempname);
		}
		else if (choice1 == 5)
		{
			creature = new HarryPotter(tempname);
		}

		creature->setTeam(1);
		player1.add(creature);
		i++;
			
	}
	//player1.display();
}

/**********************************************************
** Function: setPlayer2()
** Description: This function allows the user to select the creatures to participate in the tournament and to give
** them unique names.  Creatures are added to the player queue.

** Parameters: int
** Pre-Conditions: None
** Post-Conditions: Creatures added to player queue.
****************************************************************/
void Game::setPlayer2(int numCreatures)
{
	int i = 0;
	player2.setSize(numCreatures);
	cout << "Player 2, select the creatures for your team: " << endl;
	while (i < numCreatures)
	{
		int choice1;
		string tempname;
		Menu();
		cin >> choice1;
		cout << endl;
		while (choice1 < 1 || choice1 > 5 || !cin) // Input validation
		{
			cout << "Invalid selection, please select a number from 1 to 6" << endl;
			cin.clear();
			cin.ignore(100, '\n');
			cin >> choice1;
		}

		cout << "Enter a custom name for your creature: " << endl;
		cin >> tempname;
		cout << endl;
		if (choice1 == 1)
		{
			creature = new Barbarian(tempname);
		}
		else if (choice1 == 2)
		{
			creature = new Medusa(tempname);
		}
		else if (choice1 == 3)
		{
			creature = new BabaYaga(tempname);
		}
		else if (choice1 == 4)
		{
			creature = new BlueMen(tempname);
		}
		else if (choice1 == 5)
		{
			creature = new HarryPotter(tempname);
		}
		creature->setTeam(2);
		player2.add(creature);
		
		i++;
		
	}
	//player2.display();
}

/**********************************************************
** Function: Combat()
** Description: This is the function that determines and records combat results between 2 player creatures.  Each
** round is continued until 1 creatures is dead.  That creature is added to the loser stack, and the winner is healed
** a random amount and returned to their player queue.  The combat function continues until one queue is empty, signifying
** a player has won the tournament.

** Parameters: 
** Pre-Conditions: Valid player queues
** Post-Conditions: Various information output to screen to update player on progress of battle.  One creature killed
** and added to loser stack.
****************************************************************/
void Game::Combat()
{
	int round = 0;
	
	while (!player1.isEmpty() && !player2.isEmpty())
	{
		creature1 = player1.remove();

		creature2 = player2.remove();

		int startStrength1 = creature1->getStrength();	// set starting strength for beginning of round
		int startStrength2 = creature2->getStrength();	// set starting strength for beginning of round

		cout << creature1->getCustomName() << " Fights " << creature2->getCustomName() << "!" << endl;
		while (creature1->getStrength() > 0 && creature2->getStrength() > 0)
		{
			/**************************************************************
			** Creature 1 attacks  here
			***********************************************/
			cout << creature2->getCustomName() << " strength remaining is: " << creature2->getStrength() << endl;
			cout << creature1->getCustomName() << " attacks " << creature2->getCustomName() << " ...." << endl;

			int cr1attack = creature1->Attack();
			if (cr1attack == 100)
			{
				cout << "Medusa used GLARE, " << creature2->getCustomName() << " is dead." << endl;
				creature2->setStrength(0);
				cout << endl;
				break;
			}

			else
			{
				cout << creature1->getCustomName() << " rolled for " << cr1attack << " damage" << endl;

				cout << creature2->getCustomName() << " defends against " << creature1->getCustomName() << " ...." << endl;

				int cr2damage = creature2->Defend(cr1attack);
				cout << creature1->getCustomName() << " did a total of " << cr2damage << " damage to " << creature2->getCustomName() << endl;
				cout << endl;
				sleep(1500);

			}

			if (creature2->getStrength() <= 0 || creature1->getStrength() >30) // If 2 BabaYagas regaining health, first to hit 30 strength wins
			{
				cout << creature2->getCustomName() << " HAS DIED!" << endl;
				cout << creature1->getCustomName() << " WINS!" << endl;
				creature1->setWins();
				creature2->setStrength(0);
				losers.add(creature2);	//creature2 added to loser stack
				player2.decSize(); // decrement size for player2
				creature1->heal();	//creature1 healed random amount
				if (creature1->getStrength() > startStrength1)	// If Baba Yaga has more than 12 strength, reset to her base value
				{
					creature1->setStrength(startStrength1);
				}
		
				player1.add(creature1);		//creature1 added back to queue
				player1pts++;
				cout << endl;

			}

			/**************************************************************
			** Creature 2 attacks next here
			***********************************************/
			else
			{
				cout << creature1->getCustomName() << " strength remaining is: " << creature1->getStrength() << endl;
				cout << creature2->getCustomName() << " attacks " << creature1->getCustomName() << " ...." << endl;

				int cr2attack = creature2->Attack();
				if (cr2attack == 100)
				{
					cout << "Medusa used GLARE, " << creature1->getCustomName() << " is dead." << endl;
					creature1->setStrength(0);
					cout << endl;
					break;
				}
				cout << creature2->getCustomName() << " rolled for " << cr2attack << " damage" << endl;

				cout << creature1->getCustomName() << " defends against " << creature2->getCustomName() << " ...." << endl;

				int cr1damage = creature1->Defend(cr2attack);
				cout << creature2->getCustomName() << " did a total of " << cr1damage << " damage to " << creature1->getCustomName() << endl;
				cout << endl;

				if (creature1->getStrength() <= 0 || creature2->getStrength()>30) // If 2 BabaYagas regaining health, first to hit 30 strength wins
				{
					cout << creature1->getCustomName() << " HAS DIED!" << endl;
					cout << creature2->getCustomName() << " WINS!" << endl;
					creature2->setWins();
					creature1->setStrength(0);
					losers.add(creature1);	// creature1 added to loser stack
					player1.decSize();  // decrement player1 size
					creature2->heal();	// creature2 healed a random amount
					if (creature2->getStrength() > startStrength2)	// If Baba Yaga has more than 12 strength, reset to her base value
					{
						creature2->setStrength(startStrength2);
					}
					player2.add(creature2);		//creature2 added back to queue
					player2pts++;
					cout << endl;
				}

				cout << endl;
				cout << endl;
				sleep(1500);
			}
		}
		round++;
		cout << "End of round " << round << endl;
		//player1.display();
		//player2.display();
		//losers.display();
		cout << "Display updated results? Enter Y/y to view or any other key to continue" << endl;
		char results;
		cin >> results;
		if(results == 'Y' || results == 'y')
		{
			cout << "Player1 queue: " << endl;
			player1.display();
			cout << "Player2 queue: " << endl;
			player2.display();
			cout << "Loser stack: " << endl;
			losers.display();
			cout << "Team 1 score: " << player1pts << endl;
			cout << "Team 2 score: " << player2pts << endl;
			sleep(1500);
			
		}
		
	}
}

/**********************************************************
** Function: results()
** Description: Displays the results of the tournament after one player has lost.  The remaining creatures in the winner
** queue are sorted by number of wins then moved into the stack with the losers.  Once all creatures are in the stack,
** the top three winners are again sorted by remaining strength (if they are tied by wins), and finally the top
** three are then displayed.

** Parameters: None
** Pre-Conditions: Valid queue, stack
** Post-Conditions: Winning player queue sorted by wins then transfered to stack.  Top 3 stack sorted by strength, displayed to screen.
****************************************************************/

void Game::results()
{
	if (player1pts > player2pts)
	{

			player1.sort();
			//player1.display();
			while (!player1.isEmpty())
			{
				losers.add(player1.remove());
			}
			//losers.display();
		
			cout << "Player 1 has won the tournament!" << endl;
	}

	if (player2pts > player1pts)
	{

			player2.sort();
			//player2.display();
			while (!player2.isEmpty())
			{
				losers.add(player2.remove());
			}
			//losers.display();
		
			cout << "Player 2 has won the tournament!" << endl;
	}
	cout << "The Top Three Finishers are: " << endl;
	Creature* winner = losers.remove();
	Creature* second = losers.remove();
	Creature* third = losers.remove();
	if (winner->getWins() == second->getWins() == third->getWins())  // If some or all of top 3 are tied by wins, sort by strength
	{
		if (second->getStrength() > winner->getStrength())
		{
			Creature* tempsec = second;
			Creature* tempwin = winner;
			second = tempwin;
			winner = tempsec;

		}
		else if (third->getStrength() > winner->getStrength())
		{
			Creature* tempth = third;
			Creature* tempwin = winner;
			third = tempwin;
			winner = tempth;

		}
		else if (third->getStrength() > second->getStrength())
		{
			Creature* tempth = third;
			Creature* tempsec = second;
			third = tempsec;
			second = tempth;

		}
	}
	 if (winner->getWins() == second->getWins())
	{
		
		if (second->getStrength() > winner->getStrength())
		{
			Creature* tempsec = second;
			Creature* tempwin = winner;
			second = tempwin;
			winner = tempsec;

		}
	}
	 if (second->getWins() == third->getWins())
	 {
		 if (third->getStrength() > second->getStrength())
		 {
			 Creature* tempsec = second;
			 Creature* tempth = third;
			 third = tempsec;
			 second = tempth;

		 }
	 }

	cout << "FIRST PLACE: " << winner->getName() << " " << winner->getCustomName() << " Team: " << winner->getTeam()
		<< " Wins: " << winner->getWins() << " Remaining strength: " << winner->getStrength() << endl << endl;

	cout << "SECOND PLACE: " << second->getName() << " " << second->getCustomName() << " Team: " << second->getTeam()
		<< " Wins: " << second->getWins() << " Remaining strength: " << second->getStrength() << endl << endl;

	cout << "THIRD PLACE: " << third->getName() << " " << third->getCustomName() << " Team: " << third->getTeam()
		<< " Wins: " << third->getWins() << " Remaining strength: " << third->getStrength() << endl << endl;

	char choice;
	cout << "Would you like to view the remaining creatures? Enter Y/y or any other key to continue" << endl;
	cin >> choice;

	if (choice == 'Y' || choice == 'y')
	{
		cout << "Remaining creatures: " << endl;
		while (!losers.isEmpty())
		{
			Creature* creature = losers.remove();
			cout << creature->getName() << " " << creature->getCustomName() << " Team: " << creature->getTeam()
				<< " Wins: " << creature->getWins() << " Remaining strength: " << creature->getStrength() << endl;
			delete creature;
			
		}
	}
	else
	{
		while (!losers.isEmpty())
		{
			Creature* creature = losers.remove();
			delete creature;
		}

		cout << "Thanks for playing!" << endl;
	}

	delete winner;
	delete second;
	delete third;

	
}