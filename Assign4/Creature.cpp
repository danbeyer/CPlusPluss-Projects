/***********************************************************************************
** Program Filename: Creature.cpp
** Author: Daniel Beyer
** Date: 05/04/16
** Description: Implementation file for class functions in Creature.hpp.
***************************************************************************/

#include<iostream>
#include<string>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include "Creature.hpp"

/**********************************************************
** Function: Creature()
** Description: Default Constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Creature object created with default values
****************************************************************/

Creature::Creature()
{
	armor = 0;
	strength = 0;
	name = "";
	customName = "";
	attackRolls = 0;
	attackSides = 0;
	defRolls = 0;
	defSides = 0;
	team = 0;
	wins = 0;
}

/**********************************************************
** Function: Creature()
** Description: Constructor
** Parameters: Int and string
** Pre-Conditions: None
** Post-Conditions: Creature object created with parameter values
****************************************************************/
Creature::Creature(string cn, int ar, int str, string na, int attackRoll, int attackSide, int defRoll, int defSide)
{
	customName = cn;
	armor = ar;
	strength = str;
	name = na;
	attackRolls = attackRoll;
	attackSides = attackSide;
	defRolls = defRoll;
	defSides = defSide;
	team = 0;
	wins = 0;
}

Creature::~Creature() // Destructor
{
	//cout << "Destructor has run" << endl;
}



/**********************************************************
** Function: Getter  and setter functions 
** Description: These are the getter and setter functions for the Creature base class.

** Parameters: int for setStrength
** Pre-Conditions: None
** Post-Conditions: int and string returned
****************************************************************/
string Creature::getName()
{
	return name;
}

int Creature::getStrength()
{
	return strength;
}

int Creature::getArmor()
{
	return armor;
}

void Creature::setStrength(int x)
{
	strength = x;
}

string Creature::getCustomName()
{
	return customName;
}

void Creature::setTeam(int x)
{
	team = x;
}
/**********************************************************
** Function: heal()
** Description: This function heals the creature a small amount if it is the winner.  Based on random number 0-5

** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Strength increased a random amount
****************************************************************/
void Creature::heal()
{
	int heal;
	heal = rand() % 5;
	cout << customName << " is healing " << heal << " points." << endl;
	strength = strength + heal;
	
}

void Creature::setWins()
{
	wins++;
}

int Creature::getWins()
{
	return wins;
}

int Creature::getTeam()
{
	return team;
}