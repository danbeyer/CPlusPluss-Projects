/***********************************************************************************
** Program Filename: Bridge.cpp
** Author: Daniel Beyer
** Date: 06/01/16
** Description: Implementation file for class functions in Bridge.hpp.
***************************************************************************/
#include "Space.hpp"
#include "Player.hpp"
#include "Inventory.hpp"
#include "Bridge.hpp"


/***********************************************************
** Function: SpecialEnter()
** Description: Player enters the specified room and performs special action specific to that room
** Parameters: Pointer to player
** Pre-Conditions: Valid player pointer
** Post-Conditions: None.
*********************************************************************/

void Bridge::specialEnter(Player *player)
{
	int choice;
	int choice2;
	std::cout << "You must get to Engineering and see how we can get our engines back up and running!" << std::endl;
	std::cout << "Who do you want to leave in charge while you are gone?" << std::endl;
	std::cout << "Press 1 to leave your Number One first officer in charge." << std::endl;
	std::cout << "Press 2 to leave the new ensign with no experience in charge." << std::endl;
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
		std::cout << "You opt to leave your trusted Number One first officer in charge, a fine choice" << std::endl;
		ensignInCharge = false;
	}
	if (choice == 2)
	{
		std::cout << "You opt to leave the new ensign in charge.  A curious choice, hopefully a wise one" << std::endl;
		ensignInCharge = true;
	}

	std::cout << "You are entering the Turbo Lift, please select your destination:" << std::endl;
	std::cout << "1. Holodeck" << std::endl;
	std::cout << "2. Sickbay" << std::endl;
	std::cout << "3. Tenforward" << std::endl;
	std::cout << "4. Engineering" << std::endl;
	std::cout << "5. View backpack contents" << std::endl;
	std::cin >> choice2;
	while (choice2 < 1 || choice2 >5 || !std::cin)
	{
		std::cout << "Invalid selection, please try again" << std::endl;
		std::cin >> choice;
		std::cin.clear();
		std::cin.ignore(256, '\n');
	}
	switch (choice2)
	{
	case 1:
		player->setLocation(holdeck);
			break;
	case 2:
		player->setLocation(sickb);
		break;
	case 3:
		player->setLocation(tenf);
		break;
	case 4:
		player->setLocation(engring);
		break;
	case 5:
		player->getInventory()->display();
		break;
	}

}

bool Bridge::getEnsigninCharge()
{
	return ensignInCharge;
}