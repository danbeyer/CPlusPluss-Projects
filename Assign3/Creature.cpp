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
	attackRolls = 0;
	attackSides = 0;
	defRolls = 0;
	defSides = 0;
}

/**********************************************************
** Function: Creature()
** Description: Constructor
** Parameters: Int and string
** Pre-Conditions: None
** Post-Conditions: Creature object created with parameter values
****************************************************************/
Creature::Creature(int ar, int str, string na, int attackRoll, int attackSide, int defRoll, int defSide)
{
	armor = ar;
	strength = str;
	name = na;
	attackRolls = attackRoll;
	attackSides = attackSide;
	defRolls = defRoll;
	defSides = defSide;
}

/**********************************************************
** Function: Attack()
** Description: This is the attack function for the base class Creature.  It sums random dice rolls to return
** an int attackValue.

** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Int attackValue returned.
****************************************************************/

int Creature::Attack()
{
	int attackValue = 0;
	for (int i = 0; i < attackRolls; i++)
	{
		attackValue += rand() % attackSides + 1;
	}

	return attackValue;

}

/**********************************************************
** Function: Defend()
** Description: This is the defend function for the base class Creature.  It accepts an attackValue as a parameter
** and determines a defense value based on random dice rolls.  If the defense value + the creature's armor value
** is greater than the attackValue, then damage is set to 0.  Otherwise, damage is calculated and the damage value
** is subtracted from the creature's remaining strength.  If the damage is greater than the remaining strength, the
** strength is set to 0 and the creature dies.

** Parameters: int attackValue
** Pre-Conditions: valid int as parameter
** Post-Conditions: Int damage returned and strength set to new value.
****************************************************************/
int Creature::Defend(int attackValue)
{
	int damage = 0;
	int defenseValue = 0;
	for (int i = 0; i < defRolls; i++)
	{
		defenseValue += rand() % attackSides + 1;
	}
	cout << getName() << " rolled for " << defenseValue << " defense" << endl;
	cout << endl;

	if (attackValue < (defenseValue + armor))
	{
		cout << "Attack damage was less than defense + armor, so no damage was taken" << endl;
		cout << endl;
		damage = 0;
	}
	else
	{
		damage = attackValue - defenseValue - armor;
	}
	

	if (damage >= strength)
	{
		strength = 0;
	}
	else
	{
		strength = strength - damage;
	}

	return damage;

}

/**********************************************************
** Function: Getter functions 
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

