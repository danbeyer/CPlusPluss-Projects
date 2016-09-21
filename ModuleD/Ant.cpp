/***********************************************************************************
** Program Filename: Ant.cpp
** Author: Daniel Beyer
** Date: 03/29/16
** Description: Implementation file for class functions in Ant.hpp.
***************************************************************************/

#include "Ant.hpp"


using namespace std;

/*****************************************************************
** Function: Ant constructor
** Description: Sets count of each Ant object to 0 
** Parameters: None
** Pre-conditions: None
** Post-conditions: None
*****************************************/

Ant::Ant()
{
	count = 0;
	type = 'A';

}

/*****************************************************************
** Function: Breed
** Description: If count is 3, a new Ant object is created and a pointer passed to the array.  If count is not
** 3, count is incremented and NULL 0 is passed to the array.

** Parameters: None
** Pre-conditions: None
** Post-conditions: New ant object created and pointer passed to array and count reset to 0, or count incremented
** and NULL pointer passed to array.
********************************************************************/
Ant* Ant::Breed()
{
	if (count == 3)
	{
		count = 0;
		return new Ant;
		
	}
	else
	{
		count++;
		return 0;
	}

}

void Ant::Eat(Critter *critter)
{

}