/***********************************************************************************
** Program Filename: Doodlebug.cpp
** Author: Daniel Beyer
** Date: 04/28/16
** Description: Implementation file for class functions in Doodlebug.hpp.
***************************************************************************/

#include "Doodlebug.hpp"

Doodlebug::Doodlebug()
{
	count = 0;
	type = 'D';
	starveMoves = 0;
}

/*****************************************************************
** Function: Breed
** Description: If count is 8, a new Doodlebug object is created and a pointer passed to the array.  If count is not
** 8, count is incremented and NULL 0 is passed to the array.

** Parameters: None
** Pre-conditions: None
** Post-conditions: New ant object created and pointer passed to array and count reset to 0, or count incremented
** and NULL pointer passed to array.
********************************************************************/
Doodlebug* Doodlebug::Breed()
{
	if (count == 8)
	{
		count = 0;
		return new Doodlebug;

	}
	else
	{
		count++;
		return 0;
	}

}

/**********************************************
** Function: Eat()
** Description: Function checks to see if the pointer passed to it it is from an Ant object.  If it is, it deletes
** the ant object.

** Parameters: Pointer to critter object
** Pre-Conditions: None
** Post-Conditions: Object deleted if it is an Ant object
****************************************************************/
void Doodlebug::Eat(Critter *critter)
{
	if (critter->getCharType() == 'A')
	{
		starveMoves = 0;
		delete critter;
	}

}
/**********************************************
** Function: Starve()
** Description: Function checks to see if the current Doodlebug object has moved 3 times without eating.  If it has,
** return true and it starves.

** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Return true or false.
****************************************************************/
bool Doodlebug::Starve()
{
	if (starveMoves == 3)
	{
		return true;
	}
	else {
		
		return false;
	}
}

/**********************************************
** Function: incrementStarveMoves()
** Description: Function increments the number of moves since eating.

** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
****************************************************************/

void Doodlebug::IncrementStarveMoves()
{
	starveMoves++;
}

int Doodlebug::getstarvemoves()
{
	return starveMoves;
}