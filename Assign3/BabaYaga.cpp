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

BabaYaga::BabaYaga() : Creature(3, 12, "Baba Yaga", 2, 6, 1, 10) {} // Constructor

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