/***********************************************************************************
** Program Filename: BlueMen.cpp
** Author: Daniel Beyer
** Date: 05/04/16
** Description: Implementation file for class functions in BlueMen.hpp.
***************************************************************************/
#include<iostream>
#include<string>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include "BlueMen.hpp"

BlueMen::BlueMen() : Creature("Blue Men", 3, 12, "Blue Men", 2, 10, 3, 6) {}

BlueMen::BlueMen(string name) : Creature(name, 3, 12, "Blue Men", 2, 10, 3, 6) {}
/**********************************************************
** Function: Attack()
** Description: This is the attack function for the class BlueMen.  It sums random dice rolls to return
** an int attackValue.

** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Int attackValue returned.
****************************************************************/
int BlueMen::Attack()
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
** Description: This is the defend function for the class BlueMen.  It accepts an attackValue as a parameter
** and determines a defense value based on random dice rolls.  If the defense value + the creature's armor value
** is greater than the attackValue, then damage is set to 0.  Otherwise, damage is calculated and the damage value
** is subtracted from the creature's remaining strength.  If the damage is greater than the remaining strength, the
** strength is set to 0 and the creature dies. BlueMen Mob ability means for every 4 points of damage, 1 dice roll is lost.

** Parameters: int attackValue
** Pre-Conditions: valid int as parameter
** Post-Conditions: Int damage returned and strength set to new value.
****************************************************************/
int BlueMen::Defend(int attackValue)
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

	if (strength <= 8 && strength > 4) // BlueMen losing die roll due to their Mob ability
	{
		defRolls = 2;
		cout << "BlueMen have 2 dice left" << endl;
	}
	if (strength <=4 && strength >0) // BlueMen losing die roll due to their Mob ability
	{
		defRolls = 1;
		cout << "BlueMen have 1 dice left" << endl;
	}

	return damage;

}