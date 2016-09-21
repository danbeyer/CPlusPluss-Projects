/***********************************************************************************
** Program Filename: Main.cpp
** Author: Daniel Beyer
** Date: 04/27/16
** Description: Main method for Module 1.  This program has 3 parts:
** 1. A function that recursively reverses a string.  The function has a single parameter of type string. 
** It will print the reversed characters to the screen followed by a newline character.
** 2. A function that recursively calculates the sum of an array.  The function has 2 parameters, 
** the array and an integer showing the number of elements in the array.  The function uses recursive call
** to sum the value of all elements.
** 3. A recursive function to calculate the Triangular Number for N.

** Input: Initial menu selection, string, ints for array, int N

** Output: Prints reversed characters of string, prints sum of all elements in array of ints, prints Triangular
** Number for N.
***************************************************************************/

#include<iostream>
#include<string>
#include "recs.hpp"

using namespace std;

int main()
{
	int option = 0;
	while (option != 4)
	{
		cout << "Welcome to Module 1.  Please make a selection from the menu below:" << endl;

		cout << "1. Reverse a string using recursion" << endl;
		cout << "2. Calculate the sum of an array using recursion" << endl;
		cout << "3. Calculate the Triangular Number N using recursion" << endl;
		cout << "4. Exit" << endl;

		cin >> option;

		while (option < 1 || option > 4 || !cin) // Input validation
		{
			cout << "Invalid selection, please select a number from 1 to 4" << endl;
			cin.clear();
			cin.ignore(100, '\n');
			cin >> option;
		}

		if (option == 1)
		{
			string str;
			cout << "Enter a string word or sentence:" << endl;
			cin.ignore(100, '\n');
			getline(cin, str);
			cout << reverse(str) << "\n";
			cout << "\n\n\n";
		}

		if (option == 2)
		{
			int size;
			int total = 0;
			int *array;
			

			cout << "Enter array size: " << endl;
			cin >> size;
			while (size < 1 || !cin)
			{
				cout << "Invalid selection, please enter an integer greater than 1" << endl;
				cin.clear();
				cin.ignore(100, '\n');
				cin >> size;
			}

			array = new int[size];

			cout << "Enter numbers into array:" << endl;
			for (int i = 0; i < size; i++)
			{
				cout << "Number " << (i + 1) << ": ";
				cin >> array[i]; 
				cout << endl;
			}

			cout << "The sum is: " << arraySum(array, size) << endl;
			cout << "\n\n\n";
			delete[] array;
		}

		if (option == 3)
		{
			int rows;
			cout << "Enter the number of rows for the base of the triangle: ";
			cin >> rows;
			while (rows < 1 || !cin)
			{
				cout << "Invalid selection, please enter an integer greater than 1" << endl;
				cin.clear();
				cin.ignore(100, '\n');
				cin >> rows;
			}
			cout << "\n\n\n";
			cout << "The triangular number for that many rows is: " << triangle(rows) << endl;
			cout << "\n\n\n";
		}
	}

	return 0;
}