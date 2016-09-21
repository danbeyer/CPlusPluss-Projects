/***********************************************************************************
** Program Filename: recursion.cpp
** Author: Daniel Beyer
** Date: 04/27/16
** Description: Implementation file for recursion functions in recs.hpp.
***************************************************************************/

#include<iostream>
#include<string>
#include "recs.hpp"

using namespace std;

/****************************************************************
** Function: reverse()
** Description: Uses recursion to reverse a string and display the reversed string to the screen

** Parameters: string
** Pre-conditions: Input string by user
** Post-conditions: New reversed string displayed to screen
***************************************************************/

string reverse(string str)
{
	if (str.length() == 0)
	{
		return str;
	}

	else
	{
		return reverse(str.substr(1, str.length())) + str.at(0);
	}
}

/*****************************************************************
** Function: arraySum()
** Description: Uses recursion to sum all the elements of an array.

** Parameters: array, int size
** Pre-conditions: array and int size passed as parameters
** Post-conditions: Sum displayed to screen
*******************************************************************/

int arraySum(int array[], int size)
{
	
	if (size == 0)
	{
		return 0;
	}

	else
	{
		return array[size-1] + arraySum(array, size - 1);
	}
	
}

/******************************************************************
** Function: triangle()
** Description:  Uses recursion to calculate the triangular number for int N.

** Parameters: int N
** Pre-conditions: 
** Post-conditions: Triangular number for N is displayed to screen.
*************************************************************************/

int triangle(int rows)
{
	if (rows == 0)
	{
		return 0;
	}

	else
	{
		return rows + triangle(rows - 1);
	}
}