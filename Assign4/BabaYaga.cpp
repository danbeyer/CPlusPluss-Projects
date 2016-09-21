/***********************************************************************************
** Program Filename: BabaYaga.cpp
** Author: Daniel Beyer
** Date: 05/04/16
** Description: Implementation file for class functions in BabaYaga.hpp.
***************************************************************************/
#include<iostream>
#include<string>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include "BabaYaga.hpp"

BabaYaga::BabaYaga() : Creature("Baba Yaga", 3, 12, "Baba Yaga", 2, 6, 1, 10) {} // Constructor

BabaYaga::BabaYaga(string name) : Creature(name, 3, 12, "Baba Yaga", 2, 6, 1, 10) {}

/**********************************************************
** Function: Attack()
** Description: This is the attack function for Baba Yaga.  It sums random dice rolls to return
** an int attackValue.  When Baba Yaga attacks, she receives 1/3 of the damage points inflicted towards her 
** own strength.

** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Int attackValue returned.
****************************************************************/

int BabaYaga::Attack()
{
	int attackValue = 0;
	for (int i = 0; i < attackRolls; i++)
	{
		attackValue += rand() % attackSides + 1;
	}

	strength += (attackValue / 3); // SOUL ABILITY
	cout << "Baba Yaga gained " << attackValue / 3 << " strength points with her SOUL ability" << endl;
	return attackValue;
}

/**********************************************************
** Function: Defend()
** Description: This is the defend function for the class BabaYaga.  It accepts an attackValue as a parameter
** and determines a defense value based on random dice rolls.  If the defense value + the creature's armor value
** is greater than the attackValue, then damage is set to 0.  Otherwise, damage is calculated and the damage value
** is subtracted from the creature's remaining strength.  If the damage is greater than the remaining strength, the
** strength is set to 0 and the creature dies.

** Parameters: int attackValue
** Pre-Conditions: valid int as parameter
** Post-Conditions: Int damage returned and strength set to new value.
****************************************************************/
int BabaYaga::Defend(int attackValue)
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