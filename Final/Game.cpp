/***********************************************************************************
** Program Filename: Game.cpp
** Author: Daniel Beyer
** Date: 05/04/16
** Description: Implementation file for class functions in Game.hpp.
***************************************************************************/
#include "Game.hpp"
#include "Space.hpp"
#include "Player.hpp"
#include "Bridge.hpp"
#include "Engineering.hpp"
#include "Holodeck.hpp"
#include "Inventory.hpp"
#include "Item.hpp"
#include "Sickbay.hpp"
#include "tenforward.hpp"
#include "Bridge2.hpp"
#include<iostream>
#include<string>

/****************************************************************************************
** Function: Game()
** Description: Default Constructor.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Game object initialized.
*******************************************************************************************/
Game::Game()
{
	bridge = new Bridge();
	tenforward = new Tenforward();
	engineering = new Engineering();
	holodeck = new Holodeck();
	sickbay = new Sickbay();
	player = new Player();

	bridge->setengring(engineering);
	bridge->setholdeck(holodeck);
	bridge->settenf(tenforward);
	bridge->setsickb(sickbay);

	tenforward->setbrdge(bridge);
	tenforward->setengring(engineering);
	tenforward->setholdeck(holodeck);
	tenforward->setsickb(sickbay);

	engineering->setbrdge(bridge);
	engineering->setholdeck(holodeck);
	engineering->setsickb(sickbay);
	engineering->settenf(tenforward);

	holodeck->setbrdge(bridge);
	holodeck->setengring(engineering);
	holodeck->setsickb(sickbay);
	holodeck->settenf(tenforward);

	sickbay->setbrdge(bridge);
	sickbay->setengring(engineering);
	sickbay->setholdeck(holodeck);
	sickbay->settenf(tenforward);

	player->setLocation(bridge);


}



/***************************************************************
** Function: play()
** Description: Main game client.  Player pointer iterates through locations until time limit is reached
** or they have won the game.
** Parameters: None
** Pre-Conditions: Valid game object has been created
** Post-Conditions: None
******************************************************/
void Game::play()
{
	Space *currentlocation;
	int timer = 0;
	while (timer < 10 && player->getsaved() == 'f')
	{
		timer++;
		std::cout << "Current timer: " << timer << std::endl;
		if (timer == 10)
		{
			std::cout << "Time ran out!  The ship was destroyed!" << std::endl;
			return;
		}

		currentlocation = player->getLocation();
		currentlocation->specialEnter(player);
		if (player->getBridgeBlewUp() == 'n')
		{
			std::cout << "Uh oh...it looks like the bridge blew up, you'll be using the backup bridge now." << std::endl;
			//delete bridge;
			bridge2 = new Bridge2();
			bridge2->setengring(engineering);
			bridge2->setholdeck(holodeck);
			bridge2->setsickb(sickbay);
			bridge2->settenf(tenforward);
			player->setBridgeBlewUp('y');
			tenforward->setbrdge(bridge2);
			tenforward->setengring(engineering);
			tenforward->setholdeck(holodeck);
			tenforward->setsickb(sickbay);

			engineering->setbrdge(bridge2);
			engineering->setholdeck(holodeck);
			engineering->setsickb(sickbay);
			engineering->settenf(tenforward);

			holodeck->setbrdge(bridge2);
			holodeck->setengring(engineering);
			holodeck->setsickb(sickbay);
			holodeck->settenf(tenforward);

			sickbay->setbrdge(bridge2);
			sickbay->setengring(engineering);
			sickbay->setholdeck(holodeck);
			sickbay->settenf(tenforward);
		}
		
	}

}

/*******************************
** Function: ~Game
** Description: Destructor to deallocate memory of dynamically allocated objects
************************************************************/
Game::~Game()
{
	delete bridge;
	delete tenforward;
	delete engineering;
	delete holodeck;
	delete sickbay;
	delete player;
	delete bridge2;
}
