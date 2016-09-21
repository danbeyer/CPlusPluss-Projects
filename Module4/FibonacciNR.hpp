/**********************************************
** File: FibonacciNR.hpp
** Author: Daniel Beyer
** Date: 06/02/16
** Description: Class declaration file hearder for FibonacciNR.cpp

** Code from http://www.codeproject.com/Tips/109443/Fibonacci-Recursive-and-Non-Recursive-C
**************************************************************/
#ifndef FIBONACCINR_HPP
#define FIBONACCINR_HPP

#include<stdio.h>

class FibonacciNR
{
public:
	FibonacciNR(const long &n);
	virtual ~FibonacciNR();
	void PrintFibonacci();
private:
	FibonacciNR();
	long Fibonacci(const long &n);
	const long* n_;
};
#endif // !FIBONACCINR_HPP
