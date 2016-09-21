/***********************************************************************************
** Program Filename: Game.hpp
** Author: Daniel Beyer
** Date: 06/0116
** Description: Class declaration file header for Game.cpp
***************************************************************************/
#ifndef GAME_HPP
#define GAME_HPP
#include<iostream>
#include "Bridge.hpp"
#include "Engineering.hpp"
#include "Holodeck.hpp"
#include "Sickbay.hpp"
#include "tenforward.hpp"
#include "Player.hpp"
#include "Space.hpp"
#include "Bridge2.hpp"

class Game
{
private:
	std::string name;
	Tenforward *tenforward;
	Bridge *bridge;
	Engineering *engineering;
	Holodeck *holodeck;
	Sickbay *sickbay;
	Player *player;
	Bridge2 *bridge2;


public:
	Game();
	void play();
	~Game();

};
#endif // !GAME_HPP
