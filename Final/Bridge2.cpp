/***********************************************************************************
** Program Filename: Bridge.cpp
** Author: Daniel Beyer
** Date: 06/01/16
** Description: Implementation file for class functions in Bridge.hpp.
***************************************************************************/
#include "Space.hpp"
#include "Player.hpp"
#include "Inventory.hpp"
#include "Bridge2.hpp"

void Bridge2::specialEnter(Player *player)
{
	int choice;
	if (hasItem)
	{
		char choice;
		std::cout << "It looks like the backup crew is all here on the backup Bridge." << std::endl;
		std::cout << "They have a yellow crystal powering the backup systems," << std::endl;
		std::cout << "But it can only be replaced by a blue crystal." << std::endl;
		std::cout << "Would you like to trade a blue cystal for their yellow crystal? Y or any other key to continue?" << std::endl;
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
					std::cout << "Select Item number to trade or 9 to exit: " << std::endl;
					player->getInventory()->display();
					std::cin >> num;
					if (num == 9)
						break;
					c = player->getInventory()->useItem(num)->getItem();
					if (c == 'B')
					{
						std::cout << "You give them the blue crystal and accept their yellow crystal" << std::endl;
						player->getInventory()->removeItem(num);
						player->getInventory()->addItem(item);
						tryAgain = false;

					}
					else
					{
						std::cout << "That is not a blue crystal!  They won't accept that!" << std::endl;
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
		std::cout << "There is nothing of interest here, you already have the yellow crystal." << std::endl;
	}

	std::cout << "You are entering the Turbo Lift, please select your destination:" << std::endl;
	std::cout << "1. Holodeck" << std::endl;
	std::cout << "2. Sickbay" << std::endl;
	std::cout << "3. Engineering" << std::endl;
	std::cout << "4. Tenforward" << std::endl;
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
		player->setLocation(engring);
		break;
	case 4:
		player->setLocation(tenf);
		break;
	case 5:
		player->getInventory()->display();
		break;
	}

}