/***********************************************************************************
** Program Filename: Queue.hpp
** Author: Daniel Beyer
** Date: 05/13/16
** Description: Class declaration file header for Queue.cpp
***************************************************************************/
#ifndef QUEUE_HPP
#define QUEUE_HPP

class Queue
{
protected:
	struct Queuenode
	{
		char value;
		Queuenode *next;
		Queuenode *prev;
		//Constructor
		Queuenode(char value2, Queuenode *next1 = NULL, Queuenode *prev1 = NULL)
		{
			value = value2;
			next = next1;
			prev = prev1;
		}
	};
	Queuenode *front;
	Queuenode *back;

public:
	Queue();
	~Queue();
	void add(char char1);
	char remove();
	void display();
	bool isEmpty() const;
};
#endif // !QUEUE_HPP
