#include <iostream>
#include "aiOverwatch.h"
#include "ai.h"
#include "human.h"


AiOverwatch::AiOverwatch(Board *theBoard)
{
	gameBoard = theBoard;
}


/*
	Constructed off the basis of the pseudocode given on the wikipedia
	webpage https://en.wikipedia.org/wiki/Minimax.

	It is a perfect player, meaning it can never lose, only tie 
*/
int AiOverwatch::minimax()
{
	// Stores the best score evaluated, initially set to the value of human player win
	int topMove = 10000;

	// Looping through all possible moves
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (gameBoard->isFree(i,j))
			{
				// Make pc move and runs through max/min call until gameover.
				gameBoard->makeMoveAi(i,j,true);
				// Make human move.
				int tempScore = maxPlay();
				// Stores the move if less than topMove
				if (tempScore <= topMove)
				{
					topMove = tempScore;
					bestMove = (10*i + j);
				}
				// Reset the modified squares
				gameBoard->clearMove(i,j);
			}
		}
	}

	return bestMove;
}


// Ai's minimizing player A's persepective
int AiOverwatch::minPlay()
{
	// If the game is over, return the score (100,0,-100) == (aiwin, tie, ailose)
	if (gameOver())
	{
		return (score());
	}

	//  Min is from  Ai's perspective so large int represents a loss
	int topMove = 10000;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (gameBoard->isFree(i,j))
			{
				gameBoard->makeMoveAi(i,j,true);
				// Move has been made, evaluate from the Human's perspective
				int tempScore = maxPlay();
				// Stores the move if less than topMove
				if (tempScore <= topMove)
				{
					topMove = tempScore;
					bestMove = (10*i + j);
				}
				gameBoard->clearMove(i,j);
			}
		}
	}

	return topMove;
}

// Maximizing score from Player's perspective
int AiOverwatch::maxPlay()
{
	// If the game is over, return the score (100,0,-100) == (aiwin, tie, ailose)
	if (gameOver())
	{
		return (score());
	}

	//  Max is from the players's perspective, topMove large minus int represents a loss.
	int topMove = -10000;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (gameBoard->isFree(i,j))
			{
				gameBoard->makeMoveAi(i,j,false);
				// Human's move, evaluate move
				int tempScore = minPlay();
				// Stores the maximum score & therefore best move.
				if (tempScore >= topMove)
				{
					topMove = tempScore;
					bestMove = (10*i + j);
				}
				gameBoard->clearMove(i,j);
			}
		}
	}

	return topMove;
}


bool AiOverwatch::gameOver()
{
	// Checks if either player has won
	if ((gameBoard->checkWin('O') || (gameBoard->checkWin('X'))))
	{
		return true;
	}
	bool emptySpace = false;
	// Check if there is any free space, return opposite
	for (int i = 0; i < 3; i++)
	{
		if ((gameBoard->isFree(i,0)) || (gameBoard->isFree(i,1)) || (gameBoard->isFree(i,2)))
		{
			emptySpace = true;
		}
	}
	return (!emptySpace);
}


int AiOverwatch::score()
{
	// Large - int represents a win for AI
	if (gameBoard->checkWin('O'))
	{
		return -100;	
	}
	// Large + int represents a win for Human
	else if (gameBoard->checkWin('X'))
	{
		return 100;
	}
	return 0; // tie situation
}