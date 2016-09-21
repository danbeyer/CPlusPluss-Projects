/***********************************************************************************
** Program Filename: Critter.hpp
** Author: Daniel Beyer
** Date: 03/29/16
** Description: Class declaration file header for Critter.cpp.
***************************************************************************/

#ifndef CRITTER_HPP
#define CRITTER_HPP


class Critter
{
private:
	
	int moves;
	int rowCoord;
	int colCoord;
	char moved;

public:
	char type;

	Critter();
	int move();
	void setBorder();
	void setBlank();
	void setCritterCoord(int rows, int cols);
	char getCharType();
	int getRowCoord();
	int getColCoord();
	int getMoves();
	char getMoved();
	void setMoved(char x);
	virtual Critter* Breed() = 0;
	virtual void Eat(Critter *critter) = 0;



};

#endif
