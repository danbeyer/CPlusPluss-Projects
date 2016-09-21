/**********************************************
** File: FibonacciNR.cpp
** Author: Daniel Beyer
** Date: 05/05/16
** Description: Class implementation file for FibonacciNR.hpp

** Code from http://www.codeproject.com/Tips/109443/Fibonacci-Recursive-and-Non-Recursive-C
**************************************************************/
#include "FibonacciNR.hpp"
#include<iostream>

FibonacciNR::FibonacciNR()
{

}

FibonacciNR::FibonacciNR(const long &n) :n_(&n)
{

}

FibonacciNR::~FibonacciNR()
{

}

long FibonacciNR::Fibonacci(const long &n)
{
	long first = 0;
	long second = 1;
	long temp = 0;
	int counter = 2;

	while (counter < n)
	{
		temp = second;
		second = first + second;
		first = temp;
		++counter;
	}

	if (n == 0)
		return 0;
	else
		return first + second;
}

void FibonacciNR::PrintFibonacci()
{
	const long result = Fibonacci(*n_);
	std::cout << "Fibonacci Number: " << result << std::endl;
}