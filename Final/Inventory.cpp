/***********************************************************************************
** Program Filename: Inventory.cpp
** Author: Daniel Beyer
** Date: 05/04/16
** Description: Implementation file for class functions in Inventory.hpp.
***************************************************************************/
#include "Inventory.hpp"

/*******************************************************
** Function: Inventory()
** Description: Defaul constructor, sets all values to NULL
** Parameters: None.
** Pre-conditions: None
** Post-Conditions: Inventory object initialized
**************************************************************/
Inventory::Inventory()
{
	numItems = 0;
	maxItems = 5;
	for (int i = 0; i < maxItems; i++)
	{
		items[i] = NULL;
	}
}
/*******************************************************
** Function: ~Inventory
** Description: Destructor
** Parameters: None
** Pre-conditions: None
** Post-Conditions: Memory deallocated
********************************************************/
Inventory::~Inventory()
{
	for (int i = 0; i < maxItems; i++)
	{
		if (items[i] != NULL)
		{
			delete items[i];
			items[i] = NULL;
		}
	}
}

/*************************************************************
** Function: addItem()
** Description: adds item to inventory
** Parameters: Pointer to item
** Pre-Conditions: Item exists
** Post-Conditions: Item added to inventory
************************************************************/
void Inventory::addItem(Item *newItem)
{
	items[numItems] = newItem;
	numItems++;
}

/**********************************************************************
** Function: removeItem()
** Description: Removes item from inventory
** Parameters: Int index of item
** Pre-Conditions: Item or Null location exists
** Post-Conditions: Item deleted and all other items shifted up in list
***************************************************/

void Inventory::removeItem(int itemNum)
{
	if (items[itemNum] != NULL)
	{
		delete items[itemNum];
		items[itemNum] = NULL;
		int next = itemNum + 1;
		while (next < maxItems && items[next] != NULL)
		{
			items[itemNum] = items[next];
			items[next] = NULL;
			++itemNum;
			++next;
		}
		--numItems;
	}
}

/******************************************************************
** Function: display()
** Description: Displays contents of inventory
** Parameters: None
** Pre-Conditions: Items in Inventory
** Post-Conditions: Items displayed to screen
****************************************************************/

void Inventory::display()
{
	if (numItems == 0)
	{
		std::cout << "You have no items!" << std::endl;
	}
	else
	{
		for (int i = 0; i < numItems; i++)
		{
			std::cout << i << ": " << items[i]->getItem() << std::endl;
		}
	}
}

/**********************************************************************
** Function: useItem()
** Description: Uses item from inventory
** Parameters: Int index of item
** Pre-Conditions: Item or Null location exists
** Post-Conditions: 
***************************************************/
Item* Inventory::useItem(int itemNum)
{
	if (numItems == 0)
	{
		std::cout << "You have no items!" << std::endl;
	}
	else
	{
		Item *tempItem = items[itemNum];
		return tempItem;
	}
}

int Inventory::getNumItems()
{
	return numItems;
}