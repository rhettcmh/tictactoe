#ifndef GAME_H
#define GAME_H
#include "board.h"
#include "player.h"
#include "human.h"
#include "ai.h"

class Game
{
public:
	/* ----- CONSTRUCTORS ----- */ 
	
	/*
	Default constructor for the gameboard, stores a pointer to the board,
 	only one board object is created in the game, modified each game.
	*/
	Game();
	Game(Board* board);


	/* ----- MENUS ----- */ 

	// Main menu either exit or redirect to the 2nd Game Option Menu
	void mainMenu();
	
	// Choose ai game or human vs human game, or go back a menu
	void gameTypeSubMenu();


	/* ----- GAMETYPES ----- */ 

	/*
	Human v human, creates two human objects,
	name inputs, passed to playerA and playerB respectively
	*/
	void humanVsHuman();

	/*
	Human v Ai, human enter name, Ai name preset;
	Human always assigned X as player piece
	*/
	void humanVsAi();
	

	/* ----- RUN GAME ----- */ 

	/*
	Runs a human game; 2 Human players, take alternate turns 
	If all moves have been made, but no win, then a tie is achieved
	*/
	void runHumanGame();

	/*
	Runs a human vs Ai Game of Tic Tac toe, plays against computer,
	which is using the minimax algo. to calculate moves from aioverwatch.
	*/
	void runAiGame();

	
	/* ----- GAME CONTROLLERS ----- */ 

	/*
	For Human vs Human, first player selects, remaining
	piece assigned to the 2nd player
	*/
	void characterSelection();

	/*
	Resets the game:
	- Brags About Victory
	- Clears Game Board
	- has option to play again against character
	*/
	void resetGame(Player *winningPlayer, Player *losingPlayer, bool tie, bool gameType);

	/*
	Redirection if the player wishes to play again?
	gameType == true is the human vs human
	gameType == false is the human vs ai
	*/
	bool playAgain();

	/*
	Displays the final scores of the game, for both players, winner at the top
	Loser at the bottom. 
	*/
	void printFinalScore(Player *winner, Player *loser);


	/* ----- GETTER FUNCTIONS ----- */ 

	Ai* getAi();
	Human* getHuman();
	Board* getBoard();

private:
	Board* gameBoard;
	Human* playerA;
	Human* playerB;
	Ai* HAL9000;
};

#endif // GAME_H