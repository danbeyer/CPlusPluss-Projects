/***********************************************************************************
** Program Filename: Space.hpp
** Author: Daniel Beyer
** Date: 06/01/16
** Description: Class declaration file header for Space.cpp
***************************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP
#include <string>
#include<iostream>
#include "Player.hpp"


class Space
{
protected:
	std::string name;
	Space *tenf;
	Space *brdge;
	Space *engring;
	Space *holdeck;
	Space *sickb;

public:
	Space(std::string n);
	virtual void specialEnter(Player *player) = 0;
	void settenf(Space *s);
	void setbrdge(Space *s);
	void setengring(Space *s);
	void setholdeck(Space *s);
	void setsickb(Space *s);
	void setName(std::string n);
	std::string getName();
	virtual ~Space();


};
#endif // !SPACE_HPP

