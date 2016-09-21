/***********************************************************************************
** Program Filename: Game.hpp
** Author: Daniel Beyer
** Date: 05/04/16
** Description: Class declaration file header for Game.cpp
***************************************************************************/
#ifndef GAME_HPP
#define GAME_HPP
#include<string>
#include "Creature.hpp"
#include "Stack.hpp"
#include "Queue.hpp"

class Game
{
protected:
	Creature* creature;
	Creature* creature1;
	Creature* creature2;
	Queue player1;
	Queue player2;
	Stack losers;
	int player1pts;
	int player2pts;

public:
	Game();
	void setPlayer1(int);
	void setPlayer2(int);
	void Combat();
	void results();

};

#endif // !GAME_HPP
