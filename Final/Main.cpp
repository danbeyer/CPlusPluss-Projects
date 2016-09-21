/***********************************************************************************
** Program Filename: Main.cpp
** Author: Daniel Beyer
** Date: 05/31/16
** Description: Main method for CS162 Final Project.
** This program is a simulation of 

** Input: Initial menu selection to chose size of teams and each lineup

** Output: Results of each combat round. At the end of the tournament, displays first, second, and third place finishers.
** Also displays which side scored the most points and an option to view the total order of creatures.

***************************************************************************/
#include<iostream>
#include "Game.hpp"
#include "Space.hpp"

int main()
{
	int choice;
	std::cout << "Welcome to the STARSHIP CATASTROPHE SIMULATOR!" << std::endl;
	std::cout << "You are the captain of a starship that is under attack and its engines are down." << std::endl;
	std::cout << "You have 8 total moves to different parts of the ship to save it." << std::endl;
	std::cout << "It is up to you to fix them! You start on your bridge..." << std::endl;
	std::cout << "Press 1 to begin the game or 2 to view the solution." << std::endl;
	std::cin >> choice;
	while (choice < 1 || choice > 2 || !std::cin)
	{
		std::cout << "Invalid selection, please try again" << std::endl;
		std::cin >> choice;
		std::cin.clear();
		std::cin.ignore(256, '\n');
	}
	if (choice == 1)
	{
		Game game;
		game.play();
		std::cout << "Thanks for playing!" << std::endl;
	}
	if (choice == 2)
	{
		std::cout << "1. Go to Holodeck." << std::endl;
		std::cout << "2. Go to Tenforward and collect blue crystal." << std::endl;
		std::cout << "3. Go to Bridge and collect Yellow crystal." << std::endl;
		std::cout << "4. Go to Sickbay and collect Red crystal." << std::endl;
		std::cout << "5. Go to Engineering and use Red crystal." << std::endl;

	}

	return 0;
}