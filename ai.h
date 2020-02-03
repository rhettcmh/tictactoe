#ifndef AI_H
#define AI_H
#include "player.h"
#include "board.h"

class Ai : public Player
{
public:
	/* ----- CONSTRUCTOR ----- */ 

	// Every Ai is called HOLMES IV, number of wins set to 0.
	Ai();


	/* ----- SETTER ----- */ 

	/*
	Sets the Ai piece always to a O, and then prints out the message about 
	what character was selected
	*/
	void setCharPieceChoice();

	/* ----- GETTER ----- */

	/*
	Moves are not made by the AI. This function is used to simplify the existing 
	game code, and if this function is called then it will report an error message
	It is used to detect an error in the code.
	*/
	int getMove();
};

#endif // AI_H