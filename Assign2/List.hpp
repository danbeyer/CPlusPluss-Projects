/***********************************************************************************
** Program Filename: List.hpp
** Author: Daniel Beyer
** Date: 04/18/16
** Description: Class declaration file header for List.cpp
***************************************************************************/

#ifndef LIST_HPP
#define LIST_HPP
#include "Item.hpp"

class List
{
private:
	int numItems;
	int listSize;
	Item* itemArray;

public:
	List();
	~List();
	void addItem(Item);
	void deleteItem(int);
	int getCount();
	double getTotal();
	void print();
	bool operator==(Item a);
};

#endif 

