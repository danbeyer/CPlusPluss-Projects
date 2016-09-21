/**********************************************
** File: State.hpp
** Author: Daniel Beyer
** Date: 05/05/16
** Description: Class declaration file hearder for State.cpp
**************************************************************/

#ifndef STATE_HPP
#define STATE_HPP
#include<queue>
using namespace std;

class State
{
protected:
	char EW, NS, direction1, direction2;
	int NrOfVehiclesAtELight, NrOfVehiclesAtWLight, NrOfVehiclesAtNLight, NrOfVehiclesAtSLight;
	int NrOfVehiclesArrive, NrOfVehiclesDepart;
	int totalDepartE, totalDepartW, totalDepartN, totalDepartS;
	int totalArrivalE, totalArrivalW, totalArrivalN, totalArrivalS;
	int totalwaitE, totalwaitW, totalwaitN, totalwaitS;
	State *nextState;
	State *head;

public:


		State(char EW1, char NS1, char directionA, char directionB, State *next1 = NULL)
		{
			EW = EW1;
			NS = NS1;
			direction1 = directionA;
			direction2 = directionB;
			nextState = next1;
			NrOfVehiclesAtELight = 0;
			NrOfVehiclesAtWLight = 0;
			NrOfVehiclesAtNLight = 0;
			NrOfVehiclesAtSLight = 0;
			totalDepartE = 0;
			totalDepartW = 0;
			totalDepartN = 0;
			totalDepartS = 0;
			totalArrivalE = 0;
			totalArrivalW = 0;
			totalArrivalN = 0;
			totalArrivalS = 0;
			head = NULL;
			totalwaitE = 0;
			totalwaitW = 0;
			totalwaitN = 0;
			totalwaitS = 0;
		}



	State() { head = NULL; }
	~State();
	void add(char EW1, char NS1, char directionA, char directionB);
	void display();
	int count();
	State* getHead() { return head; }
	char getEW();
	char getNS();
	void nrOfVehiclesDepart(queue<int> &E, queue<int> &W, queue<int> &N, queue<int> &S, int x);
	void nrOfVehiclesArrive(queue<int> &E, queue<int> &W, queue<int> &N, queue<int> &S, int x);
	State* getnextState();
	int getNrOfVehiclesAtELight() { return NrOfVehiclesAtELight; }
	int getNrOfVehiclesAtWLight() { return NrOfVehiclesAtWLight; }
	int getNrOfVehiclesAtNLight() { return NrOfVehiclesAtNLight; }
	int getNrOfVehiclesAtSLight() { return NrOfVehiclesAtSLight; }
	int gettotalDepartE() { return totalDepartE; }
	int gettotalDepartW() { return totalDepartW; }
	int gettotalDepartN() { return totalDepartN; }
	int gettotalDepartS() { return totalDepartS; }
	int gettotalArrivalE() { return totalArrivalE; }
	int gettotalArrivalW() { return totalArrivalW; }
	int gettotalArrivalN() { return totalArrivalN; }
	int gettotalArrivalS() { return totalArrivalS; }
	int gettotalwaitE() { return totalwaitE; }
	int gettotalwaitW() { return totalwaitW; }
	int gettotalwaitN() { return totalwaitN; }
	int gettotalwaitS() { return totalwaitS; }

};

#endif // !STATE_HPP

