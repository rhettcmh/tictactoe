#ifndef AIOVERWATCH_H
#define AIOVERWATCH_H
#include "board.h"
#include "ai.h"
#include "human.h"

class AiOverwatch
{
public:
	/* ----- CONSTRUCTOR----- */

	// Constructor for the AiOverwatch, gets a ptr to the gameboard
	AiOverwatch(Board* theBoard);


	/* ----- MINIMAX MAIN FUNCTIONS ----- */

	/*
	Minimax main function, returns the best move 
	Requires access to both players and Game, hence it is in its own class.
	Calls between min and maxPlay functions.
	It keeps track of the minimum score (best move)!
	*/
	int minimax();

	/*
	Minimizing player, i.e. the computer player
	When it's the computer's turn, a.i needs to choose a move that 
	minimizes the Human's possible positive outcomes after that.
	*/
	int minPlay();

	/*
	Maximizing player, i.e. the human player
	When it's the human's move it chooses a move to maximize its score
	*/
	int maxPlay();


	/* ----- GAME CHECK FUNCTIONS ----- */

	/*
	Part of the min,max play functions, checks if either the minimizer
	or maximizer has won. If the board has empty spaces, return false, as empty
	space means no one has won!
	*/
	bool gameOver();

	/*
	Score counter for winning, minimax does all the static evaluations and potential
	outcomes of the game, where 0 means a tie.
	*/
	int score();
	
private:
	Board *gameBoard;
	int bestMove;
};

#endif // AIOVERWATCH_H