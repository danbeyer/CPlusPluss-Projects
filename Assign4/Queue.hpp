/***********************************************************************************
** Program Filename: Queue.hpp
** Author: Daniel Beyer
** Date: 05/13/16
** Description: Class declaration file header for Queue.cpp
***************************************************************************/
#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "Creature.hpp"

class Queue
{
protected:
	struct Queuenode
	{
		Creature* value;
		Queuenode *next;
		Queuenode *prev;
		//Constructor
		Queuenode(Creature* value2, Queuenode *next1 = NULL, Queuenode *prev1 = NULL)
		{
			value = value2;
			next = next1;
			prev = prev1;
		}
	};
	Queuenode *front;
	Queuenode *back;
	int size;

public:
	Queue();
	~Queue();
	void add(Creature*);
	Creature* remove();
	void display();
	bool isEmpty() const;
	int getSize();
	void setSize(int);
	void decSize();
	void sort();

};
#endif // !QUEUE_HPP
