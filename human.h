#ifndef HUMAN_H
#define HUMAN_H
#include "player.h"

class Human : public Player
{
public:
	/* ----- CONSTRUCTORS ----- */ 
	
	// Default constructor makes the person unnamed, and sets value of wins to 0.
	Human();

	// 2nd constructor sets name additionally to an entered name
	Human(std::string name);


	/* ----- SETTERS ----- */

	/*
	First player of the game gets to choose their player piece
	Second player does not, checks if the piece is set as a X or an O,
	only accepts those two as the inputs
	*/
	void setCharPieceChoice();

	/* ----- GETTERS ----- */

	/*
	Takes a user input for an x and y value for the location.
	They would like to move their piece into. X and Y are switched
	in the cin, to make it more intuitive to the player as a x, y positioning
	system
	*/
	int getMove();
};

#endif // HUMAN_H