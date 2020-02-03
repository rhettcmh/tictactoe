#include <iostream>
#include <cstdlib>
#include "board.h"
#include "player.h"
#include "human.h"
#include "ai.h"

Board::Board()
{
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			gameStore[x][y] = ' ';
		}
	}
}


void Board::drawBoard()
{
	// Top border
	std::cout << "+---+---+---+" << std::endl;
	// Loop for middle borders and gameboard positions
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			// LHS col. border
			if (y == 0)
			{
				std::cout << "| ";
			}

			// Prints gameboard entries with borders
			if (y < 2)
			{
				std::cout << gameStore[x][y] << " | ";
			}
			else
			{
				std::cout << gameStore[x][y] << " |" << std::endl;
				std::cout << "+---+---+---+" << std::endl;
			}
		}
	}
}


void Board::clearBoard()
{
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			gameStore[x][y] = ' ';
		}
	}
}


void Board::clearMove(int x, int y)
{
	gameStore[x][y] = ' ';
}


bool Board::isFree(int x, int y)
{
	if (gameStore[x][y] == ' ')
	{
		return true;
	}
	return false;
}


void Board::victoryBrag(Player* playerA)
{
	// Middle row of board to WIN
	gameStore[1][0] = 'W';
	gameStore[1][1] = 'I';
	gameStore[1][2] = 'N';

	// Rest of board to winning piece
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			if (x != 1)
			{
				gameStore[x][y] = playerA->getPlayerPiece();
			}
		}
	}
	drawBoard();
}


void Board::tieSad()
{
	// MIDDLE ROW TO TIE
	gameStore[1][0] = 'T';
	gameStore[1][1] = 'I';
	gameStore[1][2] = 'E';

	for (int y = 0; y < 3; y++)
	{
		gameStore[0][y] = 'X';
		gameStore[2][y] = 'O';
	}
	drawBoard();
}


bool Board::checkWin(char playerChar)
{
	for (int i = 0; i < 3; i++)
	{
		// Check horizontal rows for a win pos
		if (gameStore[i][0] == playerChar && gameStore[i][1] == playerChar 
			&& gameStore[i][2] == playerChar)
		{
			return true;
		}

		// Check verticle colms for a win position
		if (gameStore[0][i] == playerChar && gameStore[1][i] == playerChar 
			&& gameStore[2][i] == playerChar)
		{
			return true;
		}
	}
		
	// Forward diagonal check
	if (gameStore[0][0] == playerChar && gameStore[1][1] == playerChar 
		&& gameStore[2][2] == playerChar)
	{
		return true;
	}
	// Reverse diagonal check
	else if (gameStore[0][2] == playerChar && gameStore[1][1] == playerChar
		&& gameStore[2][0] == playerChar)
	{
		return true;
	}
	return false;
}


void Board::makeMove(Player* player, int x, int y)
{
	// If a move is valid, put piece there and print whose move is next
	if (isFree(x,y))
	{
		std::system("clear");
		gameStore[x][y] = player->getPlayerPiece();
		std::cout << player->getName() << "'s move: " << std::endl;
	}
	else
	{
		std::cout << "Invalid Move! That Square is already occupied." << std::endl;
		int attempt2 = player->getMove();
		// If AI get move function is called, AiOverwatch has failed horribly
		if (attempt2 == -1)
		{
			std::cout << "ERROR! AIOVERWATCH HAS FAILED!" 	<< std::endl;
			std::cout << "RECALL IMMEDIATELY, GET PROGRAMMERS!" 	<< std:: endl;
			exit(0);
		}
		makeMove(player, attempt2/10, attempt2%10);
	}
}

// Makes move for Ai game.
void Board::makeMoveAi(int x, int y, bool ai)
{
	if (ai)
	{
		gameStore[x][y] = 'O';
	}
	else
	{
		gameStore[x][y] = 'X';
	}
}
 
