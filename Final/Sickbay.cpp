/***********************************************************************************
** Program Filename: Sickbay.cpp
** Author: Daniel Beyer
** Date: 06/01/16
** Description: Implementation file for class functions in Sickbay.hpp.
***************************************************************************/
#include "Space.hpp"
#include "Player.hpp"
#include "Inventory.hpp"
#include "Sickbay.hpp"

/***********************************************************
** Function: SpecialEnter()
** Description: Player enters the specified room and performs special action specific to that room
** Parameters: Pointer to player
** Pre-Conditions: Valid player pointer
** Post-Conditions: None.
*********************************************************************/
void Sickbay::specialEnter(Player *player)
{
	int choice;
	if (hasItem)
	{
		char choice1;
		std::cout << "It appears as though one of the life support machines runs on a red crystal!  You need it!" << std::endl;
		std::cout << "The doctor tells you that the machine can also run on a yellow crystal." << std::endl;
		std::cout << "Would you like to trade a yellow crystal for the doctor's red crystal? Y or any other key to continue?" << std::endl;
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
					std::cout << "Select Item number to trade or 9 to exit: " << std::endl;
					player->getInventory()->display();
					std::cin >> num;
					if (num == 9)
						break;
					c = player->getInventory()->useItem(num)->getItem();
					if (c == 'Y')
					{
						std::cout << "You give her your yellow crystal and accept her red crystal" << std::endl;
						player->getInventory()->removeItem(num);
						player->getInventory()->addItem(item);
						tryagain = false;

					}
					else
					{
						std::cout << "That is not a yellow crystal!  She won't accept that!" << std::endl;
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
	std::cout << "2. Tenforward" << std::endl;
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
		player->setLocation(tenf);
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