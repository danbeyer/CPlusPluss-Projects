/***********************************************************************************
** Program Filename: Creature.hpp
** Author: Daniel Beyer
** Date: 05/04/16
** Description: Class declaration file header for Creature.cpp
***************************************************************************/

#ifndef CREATURE_HPP
#define CREATURE_HPP
#include<string>

using namespace std;

class Creature
{
protected:
	int armor;
	int strength;
	string name;
	int attackRolls;
	int attackSides;
	int defRolls;
	int defSides;


public:
	Creature();
	Creature(int armor, int strenth, string name, int attackRolls, int attackSides, int defRolls, int defSides);
	string getName();
	int getStrength();
	int getArmor();
	void setStrength(int);
	virtual int Attack();
	virtual int Defend(int attackValue);

};


#endif 
