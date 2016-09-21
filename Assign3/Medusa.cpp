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

Medusa::Medusa() : Creature(3, 8, "Medusa", 2, 6, 1, 6) {} // Constructor using base constructor

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

