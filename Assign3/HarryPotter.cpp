/***********************************************************************************
** Program Filename: HarryPotter.cpp
** Author: Daniel Beyer
** Date: 05/04/16
** Description: Implementation file for class functions in HarryPotter.hpp.
***************************************************************************/
#include<iostream>
#include<string>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include "HarryPotter.hpp"

HarryPotter::HarryPotter() : Creature(0, 10, "Harry Potter", 2, 6, 2, 6) // Constructor
{
	hasDied = false;
}

/**********************************************************
** Function: Defend()
** Description: This is the defend function for Harry Potter.  It accepts an attackValue as a parameter
** and determines a defense value based on random dice rolls.  If the defense value + the creature's armor value
** is greater than the attackValue, then damage is set to 0.  Otherwise, damage is calculated and the damage value
** is subtracted from the creature's remaining strength.  If the damage is greater than the remaining strength, the
** strength is set to 0 and the creature dies.  If Harry dies, he recovers and his strength becomes 20. If he dies again,
** he stays dead.

** Parameters: int attackValue
** Pre-Conditions: valid int as parameter
** Post-Conditions: Int damage returned and strength set to new value.
****************************************************************/
int HarryPotter::Defend(int attackValue)
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


	if (strength <= damage && hasDied == false)
	{
		strength = 20;
		hasDied = true;
		cout << "Harry has died but used his Hogwarts ability, he now has strength of 20" << endl;
	}
	else if (damage >= strength && hasDied == true)
	{
		strength = 0;
	}
	else
	{
		strength = strength - damage;
	}

	return damage;

}