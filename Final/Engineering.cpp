/***********************************************************************************
** Program Filename: Engineering.cpp
** Author: Daniel Beyer
** Date: 06/01/16
** Description: Implementation file for class functions in Engineering.hpp.
***************************************************************************/
#include "Space.hpp"
#include "Player.hpp"
#include "Inventory.hpp"
#include "Engineering.hpp"




/***********************************************************
** Function: SpecialEnter()
** Description: Player enters the specified room and performs special action specific to that room
** Parameters: Pointer to player
** Pre-Conditions: Valid player pointer
** Post-Conditions: None.
*********************************************************************/

void Engineering::specialEnter(Player *player)
{
	int choice;
	char choice1;
	
	std::cout << "It looks like the engines need a red communicator crystal to be repaired." << std::endl;
	std::cout << "Would you like to use the red crystal from your backpack on the engines? Y or any other key to continue?" << std::endl;
	std::cin >> choice1;
	if (choice1 == 'Y' || choice1 == 'y')
	{
		if (player->getInventory()->getNumItems() != 0)
		{
			bool tryagain = true;
			while (tryagain == true)
			{
				int num;
				char c;
				std::cout << "Select Item number to use or 9 to exit: " << std::endl;
				player->getInventory()->display();
				std::cin >> num;
				if (num == 9)
					break;
					c = player->getInventory()->useItem(num)->getItem();
					if (c == 'R')
					{
						std::cout << "You use the red crystal on the engines and start right up!  Time to get out of here!" << std::endl;
						std::cout << "You WIN!" << std::endl;
						player->getInventory()->removeItem(num);
						player->setSaved('y');
						tryagain = false;
						return;
					}
					else
					{
						std::cout << "That is not the red crystal!" << std::endl;
					}

			}
		}
		else
		{
			std::cout << "You have no crystals." << std::endl;
		}
	}
	std::cout << "You are entering the Turbo Lift, please select your destination:" << std::endl;
	std::cout << "1. Holodeck" << std::endl;
	std::cout << "2. Tenforward" << std::endl;
	std::cout << "3. Bridge" << std::endl;
	std::cout << "4. Sickbay" << std::endl;
	std::cout << "5. View backpack contents" << std::endl;
	std::cin >> choice;
	while (choice < 1 || choice >5 || !std::cin)
	{
		std::cout << "Invalid selection, please try again" << std::endl;
		std::cin >> choice;
		std::cin.clear();
		std::cin.ignore(256, '\n');
	}
	switch (choice)
	{
	case 1:
		player->setLocation(holdeck);
		break;
	case 2:
		player->setLocation(tenf);
		break;
	case 3:
		player->setLocation(brdge);
		break;
	case 4:
		player->setLocation(sickb);
		break;
	case 5:
		player->getInventory()->display();
		break;
	}

}