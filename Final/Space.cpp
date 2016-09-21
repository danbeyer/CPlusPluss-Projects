/***********************************************************************************
** Program Filename: Space.cpp
** Author: Daniel Beyer
** Date: 06/01/16
** Description: Implementation file for class functions in Space.hpp.
***************************************************************************/
#include "Space.hpp"
#include "Player.hpp"
#include<iostream>
#include<string>


/*******************************************************
** Function: Space()
** Description: Constructor
********************************************************/

Space::Space(std::string n)
{
	name = n;
	tenf = NULL;
	brdge = NULL;
	engring = NULL;
	holdeck = NULL;
	sickb = NULL;
}

/*************************************************
** Setter functions for the pointers to other Space objects
*******************************************************/
void Space::setbrdge(Space *s)
{
	brdge = s;
}

void Space::setengring(Space *s)
{
	engring = s;
}

void Space::setholdeck(Space *s)
{
	holdeck = s;
}

void Space::setsickb(Space *s)
{
	sickb = s;
}

void Space::settenf(Space *s)
{
	tenf = s;
}

void Space::setName(std::string n)
{
	name = n;
}

std::string Space::getName()
{
	return name;
}

/*****************************************************
** Function: ~Space
** Description: Destructor to free allocated memory
*********************************************************/
Space::~Space()
{

}