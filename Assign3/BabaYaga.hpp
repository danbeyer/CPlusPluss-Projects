/***********************************************************************************
** Program Filename: BabaYaga.hpp
** Author: Daniel Beyer
** Date: 05/04/16
** Description: Class declaration file header for BabaYaga.cpp
***************************************************************************/

#ifndef BABAYAGA_HPP
#define BABAYAGA_HPP
#include "Creature.hpp"

class BabaYaga : public Creature
{
protected:

public:
	BabaYaga();
	int Attack();
};
#endif // !BABAYAGA_HPP

