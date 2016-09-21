/***********************************************************************************
** Program Filename: Queue.hpp
** Author: Daniel Beyer
** Date: 05/27/16
** Description: Class declaration file header for Queue.cpp
***************************************************************************/
#ifndef QUEUE_HPP
#define QUEUE_HPP

class Queue
{
protected:
	struct Queuenode
	{
		int value;
		Queuenode *next;
		Queuenode *prev;
		//Constructor
		Queuenode(int value2, Queuenode *next1 = NULL, Queuenode *prev1 = NULL)
		{
			value = value2;
			next = next1;
			prev = prev1;
		}
	};
	Queuenode *front;
	Queuenode *back;
	int sumWait;

public:
	Queue();
	~Queue();
	void add(int value1);
	int remove();
	void display();
	bool isEmpty() const;
	int getWaitTotal();
	void addWaitTime(int);

};
#endif // !QUEUE_HPP

