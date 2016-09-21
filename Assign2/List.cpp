/***********************************************************************************
** Program Filename: List.cpp
** Author: Daniel Beyer
** Date: 04/18/16
** Description: Implementation file for class functions in List.hpp.
***************************************************************************/


#include "List.hpp"
#include<string>
#include<iostream>

using namespace std;

/*************************************************************
** Function: List
** Description: This is the default constructor for List, it sets all variables to default values.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: List variables set to default values.
**********************************************************************/
List::List()
{
	numItems = 0;
	listSize = 4;
	itemArray = new Item[listSize];
}

/*************************************************************
** Function: Destructor
** Description: Deletes itemArray to free allocated memory
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Allocated memory freed.
**********************************************************************/
List::~List()
{
	delete[]itemArray;
	cout << "deleting array" << endl;
}

/*************************************************************
** Function: addItem
** Description: Adds an item to the List array
** Parameters: Item
** Pre-Conditions: None
** Post-Conditions: Item object added to List array.
**********************************************************************/

void List::addItem(Item item)
{
	if (numItems == listSize)
	{
		Item* tempArray = new Item[listSize];
		for (int i = 0; i < listSize; i++)
		{
			tempArray[i] = itemArray[i];
		}
		listSize++;

		itemArray = new Item[listSize];

		for (int i = 0; i < listSize; i++)
		{
			itemArray[i] = tempArray[i];
		}
		delete[]tempArray;

		itemArray[numItems] = item;
		numItems++;
		
	}
	else
	{
		itemArray[numItems] = item;
		numItems++;
	}
}

/*************************************************************
** Function: print
** Description: Prints Grocery List
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: List itemArray printed to screen
**********************************************************************/
void List::print()
{
	for (int i=0; i < numItems; i++)
	{
		cout << i + 1 << ".  ";
		cout << "ITEM: " << itemArray[i].getItemName() << " ";
		cout << "UNIT: " << itemArray[i].getItemUnit() << " ";
		cout << "PRICE: " << itemArray[i].getItemPrice() << " ";
		cout << "QUANTITY: " << itemArray[i].getItemQuantity() << " ";
		cout << "TOTAL ITEM COST: " << itemArray[i].getItemTotal();
		cout << endl;
		cout << endl;
	}
	cout << "Total cost for list: " << getTotal() << endl;
	cout << endl;
}

/*************************************************************
** Function: getTotal
** Description: Returns total cost of grocery list by adding up the individual item totals
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Returns double.
**********************************************************************/

double List::getTotal()
{
	double total = 0;
	for (int i = 0; i < numItems; i++)
	{
		total += itemArray[i].getItemTotal();
	}
	return total;
}

/*************************************************************
** Function: getCount
** Description: returns numItems
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
**********************************************************************/

int List::getCount()
{
	return numItems;
}

/*************************************************************
** Function: deleteItem
** Description: Deletes an item from the list array
** Parameters: int num
** Pre-Conditions: None
** Post-Conditions: Item object deleted from List array.
**********************************************************************/
void List::deleteItem(int num)
{
	Item* tempArray = new Item[listSize];
	for (int i = 0; i < num; i++)
	{
		tempArray[i] = itemArray[i];
	}
	for (int i = num + 1; i < listSize; i++)
	{
		tempArray[i-1] = itemArray[i];
	}
	for (int i = 0; i < listSize; i++)
	{
		itemArray[i] = tempArray[i];
	}
	numItems--;
	delete[]tempArray;
}

/*************************************************************
** Function: operator==(string)
** Description: Overloaded == operator compares string parameter to List array to see if that Item is already 
** in the array.
** Parameters: string
** Pre-Conditions: None
** Post-Conditions: Returns true if already present, false if not.
**********************************************************************/

bool List::operator==(Item a)
{
	for (int i=0; i < numItems; i++)
	{
		if (itemArray[i].getItemName() == a.getItemName())
		{
			return true;
		}

	}
	return false;
}