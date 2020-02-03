#ifndef BOARD_H
#define BOARD_H
#include "player.h"

class Board
{
public:
	/* ----- CONSTRUCTORS ----- */

	/*
	Constructor for board, sets all values in the board
	to the ' ' character, meaning an empty space
	*/
	Board();


	/* ----- BOARD MODIFIERS & POS CHECKER ----- */

	// Prints gameboard with a border
	void drawBoard();

	// Sets all the characters in the board to ' ' (empty space)
	void clearBoard();

	// Removes a move, which is only used for the AiOverwatch code.
	void clearMove(int x, int y);

	// Returns true or false if a give spot is empty or clear
	bool isFree(int x, int y);


	/* ----- WIN/TIE/LOSE FUNCTIONS ----- */

	/*
	Prints win in the middle row, surrounded by the winning 
	player's characters in top and bottom row
	*/
	void victoryBrag(Player* playerA);

	/*
	Prints a Tie message in the middle row, top row is O pieces,
	bottom is X pieces.
	*/
	void tieSad();

	// Returns true if the Ai program finds a win, with a char entry.
	bool checkWin(char playerChar);

	
	/* ----- MOVE MAKERS ----- */

	/*
	Makes a human move for the human game, gets player, and two positions
	If move is not valid, continues for a user input until a valid
	move has been entered
	*/
	void makeMove(Player* player, int x, int y);

	// Makes a move for the AI based game.
	void makeMoveAi(int x, int y, bool ai);


	/* ----- GAMEBOARD! ----- */

	// Tic Tac Toe Gameboard for Each Game;
	char gameStore[3][3];
};

#endif // BOARD_H