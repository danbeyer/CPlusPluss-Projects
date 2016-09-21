/***********************************************************************************
** Program Filename: Medusa.cpp
** Author: Daniel Beyer
** Date: 05/04/16
** Description: Implementation file for class functions in Medusa.hpp.
***************************************************************************/

#include<iostream>
#include<string>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include "Medusa.hpp"

Medusa::Medusa() : Creature("Medusa", 3, 8, "Medusa", 2, 6, 1, 6) {} // Constructor using base constructor

Medusa::Medusa(string name) : Creature(name, 3, 8, "Medusa", 2, 6, 1, 6) {}
/**********************************************************
** Function: Attack()
** Description: This is the attack function for the Medusa class.  It sums random dice rolls to return
** an int attackValue.  If the attackValue rolled is 12, then the class performs GLARE and the opponent is 
** killed.

** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Int attackValue returned.
****************************************************************/

int Medusa::Attack()
{
	int attackValue = 0;
	for (int i = 0; i < attackRolls; i++)
	{
		attackValue += rand() % attackSides + 1;
	}
	if (attackValue == 12)
	{
		attackValue = 100;
	}
	return attackValue;

}

/**********************************************************
** Function: Defend()
** Description: This is the defend function for the class Medusa.  It accepts an attackValue as a parameter
** and determines a defense value based on random dice rolls.  If the defense value + the creature's armor value
** is greater than the attackValue, then damage is set to 0.  Otherwise, damage is calculated and the damage value
** is subtracted from the creature's remaining strength.  If the damage is greater than the remaining strength, the
** strength is set to 0 and the creature dies.

** Parameters: int attackValue
** Pre-Conditions: valid int as parameter
** Post-Conditions: Int damage returned and strength set to new value.
****************************************************************/
int Medusa::Defend(int attackValue)
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
