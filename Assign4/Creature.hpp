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
	string customName;
	string name;
	int attackRolls;
	int attackSides;
	int defRolls;
	int defSides;
	int team;
	int wins;


public:
	Creature();
	Creature(string customName, int armor, int strenth, string name, int attackRolls, int attackSides, int defRolls, int defSides);
	virtual ~Creature();
	string getName();
	string getCustomName();
	int getStrength();
	int getArmor();
	void setStrength(int);
	virtual int Attack() = 0;
	virtual int Defend(int attackValue) = 0;
	void setTeam(int);
	void heal();
	void setWins();
	int getWins();
	int getTeam();
};


#endif 
