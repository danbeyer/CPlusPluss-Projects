/**********************************************
** File: FibonacciR.cpp
** Author: Daniel Beyer
** Date: 05/05/16
** Description: Class implementation file for FibonacciR.hpp

** Code from http://www.codeproject.com/Tips/109443/Fibonacci-Recursive-and-Non-Recursive-C
**************************************************************/
#include "FibonacciR.hpp"
#include<iostream>

FibonacciR::FibonacciR()
{

}

FibonacciR::FibonacciR(const int &n) :n_(&n)
{

}

FibonacciR::~FibonacciR()
{

}

int FibonacciR::Fibonacci(const int &n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

void FibonacciR::PrintFibonacci()
{
	int FibonacciNum = Fibonacci(*n_);
	std::cout << *n_ << "th fibonacci number: " << FibonacciNum << std::endl;
}
