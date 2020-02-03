#include <iostream>
#include "ai.h"
#include "player.h"
#include "board.h"
#include "game.h"

Ai::Ai()
{
	name = "HOLMES IV";
	numberOfWins = 0;
}


void Ai::setCharPieceChoice()
{
	playerPiece = 'O';
	std::cout << name << ", your character is: " << playerPiece << std::endl;
}


// If this function is ever called it's a big error, program exits w/error.
int Ai::getMove()
{
	return -1;
}