/**********************************************
** File: FibonacciR.hpp
** Author: Daniel Beyer
** Date: 06/02/16
** Description: Class declaration file hearder for FibnoacciR.cpp

** Code from http://www.codeproject.com/Tips/109443/Fibonacci-Recursive-and-Non-Recursive-C
**************************************************************/
#ifndef FIBONACCIR_HPP
#define FIBONACCIR_HPP

#include<stdio.h>

class FibonacciR
{
public:
	
	FibonacciR(const int &n);
	virtual ~FibonacciR();
	void PrintFibonacci();
private:
	FibonacciR();
	int Fibonacci(const int &n);
	const int *n_;
};
#endif // !FIBONACCIR_HPP
