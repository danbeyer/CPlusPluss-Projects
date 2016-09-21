/***********************************************************************************
** Program Filename: Grid.hpp
** Author: Daniel Beyer
** Date: 03/29/16
** Description: Class declaration file header for Grid.cpp
***************************************************************************/
#ifndef GRID_HPP
#define GRID_HPP


class Grid
{
private:

	char **arr;
	int numRows;
	int numCols;

public:

	Grid(int rows, int cols);
	int getRows();
	int getCols();
	void fill(int rows, int cols);
	void print();
	void remove(int y);
	void updateLocation(int rowC, int colC);
	char getColor(int row, int col);
	void setColorWhite(int row, int col);
	void setColorBlack(int row, int col);
};
#endif