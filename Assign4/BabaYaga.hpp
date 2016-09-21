/***********************************************************************************
** Program Filename: BabaYaga.hpp
** Author: Daniel Beyer
** Date: 05/04/16
** Description: Class declaration file header for BabaYaga.cpp
***************************************************************************/

#ifndef BABAYAGA_HPP
#define BABAYAGA_HPP
#include<string>
#include "Creature.hpp"

class BabaYaga : public Creature
{
protected:

public:
	BabaYaga();
	BabaYaga(string name);
	int Attack();
	int Defend(int attackValue);
};
#endif // !BABAYAGA_HPP

