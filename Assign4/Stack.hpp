/***********************************************************************************
** Program Filename: Stack.hpp
** Author: Daniel Beyer
** Date: 05/13/16
** Description: Class declaration file header for Stack.cpp
***************************************************************************/
#ifndef STACK_HPP
#define STACK_HPP
#include "Creature.hpp"

class Stack
{
protected:
	struct Stacknode
	{
		Creature* value;
		Stacknode *next;
		//Constructor
		Stacknode(Creature* value1, Stacknode *next1 = NULL)
		{
			value = value1;
			next = next1;
		}
	};
	Stacknode *top;

public:
	Stack();
	~Stack();
	void add(Creature*);
	Creature* remove();
	void display();
	bool isEmpty() const;


};



#endif // !STACK_HPP

