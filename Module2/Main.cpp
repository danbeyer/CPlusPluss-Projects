/***********************************************************************************
** Program Filename: Main.cpp
** Author: Daniel Beyer
** Date: 05/13/16
** Description: Main method for Module2.  This program implements a stack class that performs Stack-like
** behavior - first in, last out (FILO), and a Queue class that performs Queue-like behavior - first in, first
** out (FIFO).  

** Input: User enters a series for characters into the stack and queue.

** Output: Stack characters are displayed in reverse order, Queue characters are displayed
***************************************************************************/
#include<iostream>
#include "Queue.hpp"
#include "Stack.hpp"
using std::cout;
using std::cin;
using std::endl;

int main()
{
	Stack s;
	Queue q;
	
	char choice1 = 'Y';
	char choice2 = 'Y';
	cout << "Welcome to Module 2 - Stack and Queue" << endl;

	while (choice1 == 'Y' || choice1 == 'y')
	{
		char char1;
		cout << "Enter a character to add to Stack: " << endl;
		cin >> char1;

		s.add(char1);
		cout << "Would you like to add another character to the stack? Enter Y or N" << endl;
		cin >> choice1;

	}

	cout << "Displaying and removing stack elements: " << endl;
	while (!s.isEmpty())
	{
		cout << s.remove() << endl;
	}


	while (choice2 == 'Y' || choice2 == 'y')
	{
		char char1;
		cout << "Enter a character to add to Queue: " << endl;
		cin >> char1;

		q.add(char1);
		cout << "Would you like to add another character to the stack? Enter Y or N" << endl;
		cin >> choice2;

	}

	cout << "Displaying and removing queue elements: " << endl;
	while (!q.isEmpty())
	{
		cout << q.remove() << endl;
	}

	return 0;
}