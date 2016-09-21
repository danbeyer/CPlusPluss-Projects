/***********************************************************************************
** Program Filename: Queue.cpp
** Author: Daniel Beyer
** Date: 05/27/16
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
Post-Conditions: Front and back pointers set to NULL, sumWait = 0;
***************************************************************************/
Queue::Queue()
{
	front = NULL;
	back = NULL;
	sumWait = 0;
}

/****************************************************************
** Function: ~Queue()
** Description: Destructorfor Queue that deallocates memory.
*************************************************/
Queue::~Queue()
{
	//cout << "destructor is running..." << endl;
	while (front != NULL)
	{
		remove();
	}
}

/*******************************************************************
** Function: add()
** Description: Creates and adds a new Queuenode struct to the end of the Queue.
** Parameters: int
** Pre-Conditions: None
** Post-Conditions: New node added.
*************************************************************************/
void Queue::add(int value1)
{

	if (front == NULL)
	{

		front = back = new Queuenode(value1);

	}

	else
	{
		Queuenode *node = new Queuenode(value1);
		node->next = NULL;
		back->next = node;
		node->prev = back;
		back = node;

	}

}

/***************************************************************
** Function: remove()
** Description: Returns the char stored in the front of the Queue, removes that node, and adjusts the pointers.

** Parameter: None
** Pre-conditions: Node exists in the stack to be removed
** Post-conditions: Node is removed
******************************************************************/
int Queue::remove()
{
	int returnInt;
	if (!front)
	{
		cout << "The Queue is empty." << endl;
		return 0;
	}

	else
	{
		

		Queuenode *temp = front; //Current front stored
		returnInt = temp->value;
		front = front->next; //front now pointing to node after it
		if (front != NULL)
		{
			front->prev = NULL;
		}
		delete temp;
		
	}

	return returnInt;
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
		cout << temp->value << "  ";
		temp = temp->next;
	}
	cout << endl;
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

int Queue::getWaitTotal()
{
	return sumWait;
}

/********************************************************
** Function: addWaitTime()
** Description: Increments the total wait time by the parameter int
**********************************************************/
void Queue::addWaitTime(int x)
{
	sumWait = sumWait + x;
}

