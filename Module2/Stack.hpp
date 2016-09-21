/***********************************************************************************
** Program Filename: Stack.hpp
** Author: Daniel Beyer
** Date: 05/13/16
** Description: Class declaration file header for Stack.cpp
***************************************************************************/
#ifndef STACK_HPP
#define STACK_HPP

class Stack
{
protected:
	struct Stacknode
	{
		char value;
		Stacknode *next;
		//Constructor
		Stacknode(char value1, Stacknode *next1 = NULL)
		{
			value = value1;
			next = next1;
		}
	};
	Stacknode *top;

public:
	Stack();
	~Stack();
	void add(char char1);
	char remove();
	void display();
	bool isEmpty() const;
};



#endif // !STACK_HPP

