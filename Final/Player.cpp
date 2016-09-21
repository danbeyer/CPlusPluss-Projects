/***********************************************************************************
** Program Filename: Player.cpp
** Author: Daniel Beyer
** Date: 05/04/16
** Description: Implementation file for class functions in Player.hpp.
***************************************************************************/
#include<iostream>
#include<string>
#include "Space.hpp"
#include "Player.hpp"
#include "Inventory.hpp"


/******************************************************************
** Function: Player()
** Description: Default Constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: New Player created
**************************************************************/
Player::Player()
{
	backpack = new Inventory();
	savedShip = 'f';
	ensignInCharge = 'n';
	bridgeBlewUp = 'n';
}

/**************************************************************
** Function: getLocation()
** Descriptions: return location of the player
** Parameters: None
*****************************************************/
Space* Player::getLocation()
{
	return location;
}

/*******************************************************
** Function: getInventory()
** Description: return inventory
********************************************************/
Inventory* Player::getInventory()
{
	return backpack;
}

/**************************************************************
** Function: setLocation()
** Description: sets player location
** Parameters: Room pointer
**************************************************/
void Player::setLocation(Space *space)
{
	location = space;
}

char Player::getsaved()
{
	return savedShip;
}

void Player::setSaved(char x)
{
	savedShip = x;
}
void Player::setBridgeBlewUp(char x)
{
	bridgeBlewUp = x;
}

void Player::setEnsignInCharge(char x)
{
	ensignInCharge = x;
}

char Player::getBridgeBlewUp()
{
	return bridgeBlewUp;
}

char Player::getEnsignInCharge()
{
	return ensignInCharge;
}

/********************************************
** Function: ~Player()
** Description: Destructor for player class
********************************************/
Player::~Player()
{
	delete backpack;
}