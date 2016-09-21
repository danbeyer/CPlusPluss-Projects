/***********************************************************************************
** Program Filename: tenforward.cpp
** Author: Daniel Beyer
** Date: 06/01/16
** Description: Implementation file for class functions in tenforward.hpp.
***************************************************************************/
#include "Space.hpp"
#include "Player.hpp"
#include "Inventory.hpp"
#include "tenforward.hpp"


/***********************************************************
** Function: SpecialEnter()
** Description: Player enters the specified room and performs special action specific to that room
** Parameters: Pointer to player
** Pre-Conditions: Valid player pointer
** Post-Conditions: None.
*********************************************************************/
void Tenforward::specialEnter(Player *player)
{
	int choice;
	if (hasItem)
	{
		char choice;
		std::cout << "You wander over to a shifty looking ensign at the bar." << std::endl;
		std::cout << "She has a blue power crystal, but she will only part with it for a green cystal." << std::endl;
		std::cout << "would you like to trade crystals with her? Enter Y or any other key to continue" << std::endl;
		std::cin >> choice;
		if (choice == 'Y' || choice == 'y')
		{
			if (player->getInventory()->getNumItems() != 0)
			{
				bool tryAgain = true;
				while (tryAgain)
				{
					int num;
					char c;
					std::cout << "Select Item number to trade: " << std::endl;
					player->getInventory()->display();
					std::cin >> num;
					c = player->getInventory()->useItem(num)->getItem();
					if (c == 'G')
					{
						std::cout << "You give her your green crystal and accept her blue crystal" << std::endl;
						std::cout << "She also gives you a bunch of other crystals...even though you don't need them" << std::endl;
						player->getInventory()->removeItem(num);
						player->getInventory()->addItem(item);
						player->getInventory()->addItem(item2);
						player->getInventory()->addItem(item3);
						tryAgain = false;
						hasItem = false;

					}
					else
					{
						std::cout << "That is not a green crystal!  She won't accept that!" << std::endl;
					}
					if (num == 0)
					{
						tryAgain = false;
					}
				}

			}
			else
			{
				std::cout << "You have no crystals to trade!" << std::endl;
			}

		}
	}
	else
	{
		std::cout << "There is nothing of interest here, you already have the blue crystal." << std::endl;
	}

	std::cout << "You are entering the Turbo Lift, please select your destination:" << std::endl;
	std::cout << "1. Holodeck" << std::endl;
	std::cout << "2. Sickbay" << std::endl;
	std::cout << "3. Bridge" << std::endl;
	std::cout << "4. Engineering" << std::endl;
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
