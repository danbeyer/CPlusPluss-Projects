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
	size = 0;
}

/****************************************************************
** Function: ~Queue()
** Description: Destructorfor Queue that deallocates memory.
*************************************************/
Queue::~Queue()
{
	//cout << "Queue destructor running..." << endl;
	Queuenode *temp = front;
	while (temp)
	{
		Queuenode *garbage = temp;
		temp = temp->next;
		delete garbage->value;
		delete garbage;
	}
}

/*******************************************************************
** Function: add()
** Description: Creates and adds a new Queuenode struct to the end of the Queue.
** Parameters: Creature pointer
** Pre-Conditions: None
** Post-Conditions: New node added.
*************************************************************************/
void Queue::add(Creature* cr)
{
	if (front == NULL)
	{
		front = new Queuenode(cr);
		back = front;
	}

	else
	{
		Queuenode *node = new Queuenode(cr);
		node->next = NULL;
		back->next = node;
		back = node;

	}
}

	/******************************
	else
	{
		Queuenode *node = front;
		while (node->next != NULL)
		{
			node = node->next;
		}
		node->next = new Queuenode(cr, NULL, node);
		while (node->next != NULL)
		{
			node = node->next;
		}
		back = node;

	
	}
	**********************/


/***************************************************************
** Function: remove()
** Description: Returns the char stored in the front of the Queue, removes that node, and adjusts the pointers.

** Parameter: None
** Pre-conditions: Node exists in the stack to be removed
** Post-conditions: Node is removed
******************************************************************/
Creature* Queue::remove()
{
	if (!front)
	{
		cout << "The Queue is empty." << endl;
		return 0;
	}

	else
	{
		Creature* tempCr = NULL;

		Queuenode *temp = front; //Current front stored
		tempCr = temp->value;
		front = front->next; //front now pointing to node after it
		if (front != NULL)
		{
			front->prev = NULL;
		}
		delete temp;
		return tempCr;
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
		cout << temp->value->getCustomName()<< " , " << temp->value->getWins() << endl;
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

int Queue::getSize()
{
	return size;
}

void Queue::sort()
{
	if (front != NULL)
	{
		Queuenode* current = front;
		Queuenode* prev = NULL;
		Queuenode* tempNode = NULL;
		int changeFlag = 0;
		for (int i = 0; i < getSize(); i++)
		{
			while (current->next != NULL)
			{
				tempNode = current->next;
				if (current->value->getWins() > tempNode->value->getWins())
				{
					changeFlag = 1;
					current->next = tempNode->next;
					tempNode->next = current;
					if (prev != NULL)
					{
						prev->next = tempNode;
					}
					prev = tempNode;
					if (front == current)
					{
						front = tempNode;
					}
					if (current->next == NULL)
					{
						back = current;
					}
				}
				else
				{
					prev = current;
					current = current->next;
				}
			}
			if (changeFlag == 0)
				break;
			else
			{
				prev = NULL;
				current = front;
				changeFlag = 0;
			}
		}
	}
}

void Queue::setSize(int x)
{
	size = x;
}

void Queue::decSize()
{
	size--;
}