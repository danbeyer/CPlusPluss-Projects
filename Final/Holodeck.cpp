/***********************************************************************************
** Program Filename: Holodeck.cpp
** Author: Daniel Beyer
** Date: 06/01/16
** Description: Implementation file for class functions in Holodeck.hpp.
***************************************************************************/
#include "Space.hpp"
#include "Player.hpp"
#include "Inventory.hpp"
#include "Holodeck.hpp"

/***********************************************************
** Function: SpecialEnter()
** Description: Player enters the specified room and performs special action specific to that room
** Parameters: Pointer to player
** Pre-Conditions: Valid player pointer
** Post-Conditions: None.
*********************************************************************/

void Holodeck::specialEnter(Player *player)
{
	if (isOn)
	{
		char choice;
		int choice2;
		std::cout << "It looks like the holodeck is powered by a green communicator crystal." << std::endl;
		std::cout << "Take green communicator crystal? Enter Y or any other key to continue" << std::endl;
		std::cin >> choice;
		if (choice == 'Y' || choice == 'y')
		{
			player->getInventory()->addItem(item);
			isOn = false;
		}
		else
		{
			std::cout << "OK, you will leave it alone for now." << std::endl;
			isOn = true;
		}

		std::cout << "You are entering the Turbo Lift, please select your destination:" << std::endl;
		std::cout << "1. tenforward" << std::endl;
		std::cout << "2. Sickbay" << std::endl;
		std::cout << "3. Bridge" << std::endl;
		std::cout << "4. Engineering" << std::endl;
		std::cout << "5. View backpack contents" << std::endl;
		std::cin >> choice2;
		while (choice2 < 1 || choice2 >5 || !std::cin)
		{
			std::cout << "Invalid selection, please try again" << std::endl;
			std::cin >> choice2;
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}
		switch (choice2)
		{
		case 1:
			player->setLocation(tenf);
			break;
		case 2:
			player->setLocation(sickb);
			break;
		case 3:
			player->setLocation(brdge);
			break;
		case 4:
			player->setLocation(engring);
			break;
		case 5:
			player->getInventory()->display();
			break;
		}
	}
	else
	{
		int choice3;
		std::cout << "The holodeck is powered down, you've already taken the crystal here." << std::endl;
		std::cout << "You are entering the Turbo Lift, please select your destination:" << std::endl;
		std::cout << "1. tenforward" << std::endl;
		std::cout << "2. Sickbay" << std::endl;
		std::cout << "3. Bridge" << std::endl;
		std::cout << "4. Engineering" << std::endl;
		std::cout << "5. View backpack contents" << std::endl;
		std::cin >> choice3;
		while (choice3 < 1 || choice3 >5 || !std::cin)
		{
			std::cout << "Invalid selection, please try again" << std::endl;
			std::cin >> choice3;
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}
		switch (choice3)
		{
		case 1:
			player->setLocation(tenf);
			break;
		case 2:
			player->setLocation(sickb);
			break;
		case 3:
			player->setLocation(brdge);
			break;
		case 4:
			player->setLocation(engring);
			break;
		case 5:
			player->getInventory()->display();
			break;
		}
	}
}