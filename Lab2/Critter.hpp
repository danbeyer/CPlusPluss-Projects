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
	char type;
	char moved;
public:
	Critter();
	int move();
	void setBorder();
	void setBlank();
	void setCritter(int rows, int cols);
	char getCharType();
	int getRowCoord();
	int getColCoord();
	int getMoves();
	char getMoved();
	void setMoved(char x);


};

#endif
