#include <iostream>
#include "board.h"
#include "game.h"


int main()
{
	// Create a new board, pass it to the game, and start game
	Board *newboard = new Board();
	Game *newgame = new Game(newboard);

	// Entering the game... 
	newgame->mainMenu();
	
	// Deleting all of the dynamic memory objects
	delete newboard;
	delete newgame;
	return 0;
}
