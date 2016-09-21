/***********************************************************************************
** Program Filename: Queue.cpp
** Author: Daniel Beyer
** Date: 05/13/16
** Description: Implementation file for class functions in Queue.hpp.
***************************************************************************/
#include<iostream>
#include "Queue.hpp"
using std::cout;
using std::endl;

/******************************************************************
** Function: Queue()
** Description: Default constructor that sets front and back pointers to NULL.
Parameters: None.
Pre-Conditions: None
Post-Conditions: Front and back pointers set to NULL.
***************************************************************************/
Queue::Queue()
{
	front = NULL;
	back = NULL;
}

/****************************************************************
** Function: ~Queue()
** Description: Destructorfor Queue that deallocates memory.
*************************************************/
Queue::~Queue()
{
	cout << "Destructor is running.." << endl;
	while (front != NULL)
	{
		remove();
	}
	//Queuenode *temp = front;
	//while (temp)
	//{
	//	Queuenode *garbage = temp;
	//	temp = temp->next;
	//	delete garbage;
	//}
}

/*******************************************************************
** Function: add()
** Description: Creates and adds a new Queuenode struct to the end of the Queue.
** Parameters: char
** Pre-Conditions: None
** Post-Conditions: New node added.
*************************************************************************/
void Queue::add(char char1)
{
	
	if (front == NULL && back == NULL)
	{
		
		front = back = new Queuenode(char1);
		
	}

	else
	{

		Queuenode *node = new Queuenode(char1);
		node->next = NULL;
		back->next = node;
		node->prev = back;
		back = node;
		
	}
	
	/***************************
	if (front == NULL)
	{
		front = new Queuenode(char1);
		back = front;
	}
	else
	{
		Queuenode *temp = front;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new Queuenode(char1, NULL, temp);
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		back = temp;
	}
	********************/
}

/***************************************************************
** Function: remove()
** Description: Returns the char stored in the front of the Queue, removes that node, and adjusts the pointers.

** Parameter: None
** Pre-conditions: Node exists in the stack to be removed
** Post-conditions: Node is removed
******************************************************************/
char Queue::remove()
{
	if (!front)
	{
		cout << "The Queue is empty." << endl;
		return 0;
	}

	else
	{
		char returnChar;
		
		Queuenode *temp = front; //Current front stored
		returnChar = temp->value;
		front = front->next; //front now pointing to node after it
		if (front != NULL)
		{
			front->prev = NULL;
		}
		delete temp;
		return returnChar;
	}
}

/****************************************************************
** Function: display()
** Description: Displays the values stored in the Queue nodes. (Primarily for testing purposes).

** Parameters: None
** Pre-conditions: None
** Post-conditions: Queue node contents displayed to screen.
***********************************************************************/

void Queue::display()
{
	Queuenode *temp = front;
	while (temp != NULL)
	{
		cout << temp->value << endl;
		temp = temp->next;
	}
}
/************************************************************
** Function: isEmpty()
** Description: Returns true if the queue is empty and false otherwise.
*********************************************************/
bool Queue::isEmpty() const
{
	if (front == NULL)
		return true;
	else
		return false;
}