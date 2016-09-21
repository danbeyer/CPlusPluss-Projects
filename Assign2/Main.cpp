/***********************************************************************************
** Program Filename: Main.cpp
** Author: Daniel Beyer
** Date: 04/18/16
** Description: Main method for Assignment 2.  This program creates a shopping list that a user can add to, 
** remove from, and print.  Each item added to the list contains a name, unit, quanitity, and price.  The total
** cost of the grocery is also generated.  

** Input: Initial menu selection, string item name, string item unit, int quantity, double price

** Output: List of items on the list with their respective names, units, quantities, and prices, along with a total.

***************************************************************************/

#include<iostream>
#include<string>
#include "List.hpp"


using namespace std;

int main() {

	cout << "Assignment 2 - Grocery List" << endl;
	int option = 0;
	List shoppingList;  //creation of List object
	while (option != 4)
	{ 

	
	cout << "Make a selection from the options below:" << endl;
	cout << "1. Add Item to Grocery List" << endl;
	cout << "2. Delete Item from Grocery List" << endl;
	cout << "3. Print Grocery List" << endl;
	cout << "4. Exit" << endl;

	cin >> option;

	while (option < 1 || option > 4 || !cin) // Input validation
	{
		cout << "Invalid selection, please select a number from 1 to 4" << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cin >> option;
	}

	if (option == 2 && shoppingList.getCount() == 0) // Input validation
	{
		cout << "Invalid option. Your Grocery List is empty! Add something first!" << endl;
		cout << "Re-enter a menu option:" << endl;
		cin.clear();
		cin.ignore(100, '\n');
		cin >> option;
	}
	
		if(option ==1)
		{
			string name, unit;
			int quantity;
			double price;

			cout << "~Add Item to Grocery List~" << endl;
			cout << endl;
			cout << "Enter name of item: " << endl;
			cin.ignore(100, '\n');
			getline(cin, name);

			cout << "Enter unit of item: " << endl;
			getline(cin, unit);

			cout << "Enter quantity of items: " << endl;
			cin >> quantity;
			while (quantity < 1 || !cin)  // Input validation
			{
				cout << "Invalid selection, please select a number greater than 1" << endl;
				cin.clear();
				cin.ignore();
				cin >> quantity;
			}

			cout << "Enter price of item: " << endl;
			cin >> price;
			while (price < 0.0 || !cin)  // Input validation
			{
				cout << "Invalid selection, please select a number greater than 0" << endl;
				cin.clear();
				cin.ignore();
				cin >> price;
			}

			Item item(name, unit, quantity, price);
			if (shoppingList == item)
			{
				cout << "This Item is already on your list!" << endl;
			}
			else
			shoppingList.addItem(item);

			
		}

		if(option == 2)
		{
			int num;
			cout << "~Delete Item from Grocery List~" << endl;
			cout << endl;
			cout << "Select Item to delete from List: " << endl;
			shoppingList.print();
			cin >> num;
			while (num<1 || num>shoppingList.getCount() || !cin)  // Input validation
			{
				cout << "Invalid selection, please select a number greater than 0 and less than the number of items" << endl;
				cin.clear();
				cin.ignore();
				cin >> num;
			}

			num = num - 1; //Setting num=num-1 because print function display is offset by 1.

			shoppingList.deleteItem(num);
			cout << "Item deleted." << endl;
			cout << "New List:" << endl;
			shoppingList.print();
			
		}

		if(option == 3)
		{
			cout << "~Print Grocery List~" << endl;
			cout << endl;
			if (shoppingList.getCount() == 0)
				cout << "Your Grocery List is empty." << endl;
			shoppingList.print();
			
		}

	}
	
	return 0;

}