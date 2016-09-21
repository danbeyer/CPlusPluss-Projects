/***********************************************************************************
** Program Filename: Main.cpp
** Author: Daniel Beyer
** Date: 05/27/16
** Description: Main method for Module 4.  This program measures the running time of Fibonacci Number algorithms
** and compares them.

** Input: User enters fibonacci number and factorial number
** Output: Displays time to find fibonacci number and factorial number

Code reference: http://www.codeproject.com/Tips/109443/Fibonacci-Recursive-and-Non-Recursive-C
***************************************************************************/
#include<iostream>
#include<stdio.h>
#include<time.h>
#include "FibonacciNR.hpp"
#include "FibonacciR.hpp"
using std::cout;
using std::cin;
using std::endl;

//function prototypes for factorial functions
long rfactorial(int n);
long factorialHelper(int n, int result);
long factorial(int);

int main()
{
	long num = 0;
	long temp = 0;

	cout << "Enter Fibonacci number to find: " << endl;
	cin >> num;
	while (num < 0 || !cin)
	{
		cout << "Enter a number greater than 0" << endl;
		cin >> num;
	}

	cout << "Calling Recursive Fibonacci Implementation" << endl;
	clock_t t;
	t = clock();
	FibonacciR recursive(num);
	recursive.PrintFibonacci();
	t = clock() - t;
	printf("It took me %d clicks (%f seconds). \n", t, ((float)t) / CLOCKS_PER_SEC);
	cout << endl;
	
	cout << "Calling Non-Recursive Fibonacci Implementation" << endl;
	clock_t t2;
	t2 = clock();
	FibonacciNR nonrecursive(num);
	nonrecursive.PrintFibonacci();
	t2 = clock() - t2;
	printf("It took me %d clicks (%f seconds). \n", t2, ((float)t2) / CLOCKS_PER_SEC);
	cout << endl;

	cout << "Enter a number for the factorial calculator: " << endl;
	cin >> num;
	while (num < 0 || !cin)
	{
		cout << "Enter a number greater than 0" << endl;
		cin >> num;
	}

	cout << "Finding factorial number using non-tail recursion" << endl;
	clock_t t3;
	t3 = clock();
	temp = rfactorial(num);
	t3 = clock() - t3;
	cout << "factorial number: " << temp << endl;
	printf("It took me %d clicks (%f seconds). \n", t3, ((float)t3) / CLOCKS_PER_SEC);
	cout << endl;

	cout << "Finding factorial number using tail recursion" << endl;
	clock_t t4;
	t4 = clock();
	temp = factorial(num);
	t4 = clock() - t4;
	cout << "factorial number: " << temp << endl;
	printf("It took me %d clicks (%f seconds). \n", t4, ((float)t4) / CLOCKS_PER_SEC);
	cout << endl;


	return 0;
}

/*********************************************************************
** Function: rfactorial
** Description: From instructions, not tail recursive function
** Parameters: Int
** Pre-conditions: Valid int
** Post-conditions: None
************************************************************/
long rfactorial(int n)
{
	if (n == 1)
		return 1;
	else
		return n*rfactorial(n - 1);
}
/*********************************************************************
** Function: factorialHelper
** Description: From instructions, tail recursive function
** Parameters: Int, Int
** Pre-conditions: Valid int
** Post-conditions: None
************************************************************/
long factorialHelper(int n, int result)
{
	if (n == 1)
		return result;
	else
		return factorialHelper(n - 1, n*result);
}

long factorial(int n)
{
	return factorialHelper(n, 1);
}