#include <iostream>
#include <cstdlib>
#include "board.h"
#include "ai.h"
#include "player.h"
#include "game.h"
#include "human.h"
#include "aiOverwatch.h"


Game::Game(){}


Game::Game(Board* board)
{
	gameBoard = board;
}


void Game::mainMenu()
{
	// Prints options
	std::cout << "MAIN MENU:"	 << std::endl
			  << "1: New Game"	 << std::endl
			  << "2: Close Game" << std::endl;
	char choice = '0';
	// Infinite loop until a valid selection is chosen
	while (true)
	{
		std::cout << "Enter your selection: ";
		std::cin >> choice;
		switch (choice)
		{
			case '1': 
				std::cout << "You have selected a new game!" << std::endl;
				gameTypeSubMenu();
				return;
			case '2':
				std::cout << "You have selected to close the game :(" << std::endl;
				return;
			default:
				std::cout << "Invalid choice, try again! ";
		}
	}
}


void Game::gameTypeSubMenu()
{
	// Prints options
	std::system("clear");
	std::cout << "Game Mode:"	 		<< std::endl
			  << "1: Human vs Human" 	<< std::endl
			  << "2: Human vs Ai" 		<< std::endl
			  << "3: Back a menu..." 	<< std::endl;

	int choice;
	// Infinite loop until a valid selection is made
	while (true)
	{
		std::cout << "Enter your selection: ";
		std::cin >> choice;
		switch (choice)
		{
			case 1: 
				humanVsHuman();
				characterSelection();
				runHumanGame();
				return;
			case 2:
				humanVsAi();
				runAiGame();
				return;
			case 3:
				mainMenu();
				return;
			default:
				std::cout << "Invalid choice, try again! ";
		}
	}
}

// Get names and passes to human objs.
void Game::humanVsHuman()
{
	std::string tempName;

	std::cout << "Enter Player 1's name: ";
	std::cin >> tempName;
	playerA = new Human(tempName);

	std::cout << "Enter Player 2's name: ";
	std::cin >> tempName;
	playerB = new Human(tempName);
}


void Game::humanVsAi()
{
	std::string tempName;
	
	std::cout << "Enter Human's name: ";
	std::cin >> tempName;
	playerA = new Human(tempName);
	// Also sets the player pieces here
	playerA->setCharPiece('X');	
	
	HAL9000 = new Ai();
	// Auto sets the AI piece
	HAL9000->setCharPieceChoice();
}


void Game::runHumanGame()
{
	int turnCounter = 0;
	gameBoard->drawBoard();
	while (turnCounter < 9)
	{
		// Player A's move
		if (turnCounter%2 == 0)
		{
			int move = playerA->getMove();
			// Places player A's move
			gameBoard->makeMove(playerA, move/10, move%10);
			// If a win achieved, go through the resetGame sequence
			if (gameBoard->checkWin(playerA->getPlayerPiece()))
			{
				resetGame(playerA, playerB, false, false);
				return;
			}
		}
		// Player B's move
		else
		{
			int move = playerB->getMove();
			// Places player B's move
			gameBoard->makeMove(playerB, move/10, move%10);
			// If a win achieved, go through the resetGame sequence
			if (gameBoard->checkWin(playerB->getPlayerPiece()))
			{
				resetGame(playerB, playerA, false, false);
				return;
			}
		}
		
		// Tie situation (no one wins)
		if (turnCounter == 8)
		{
			resetGame(playerA, playerB, true, false);
			return;
		}
		// Once turn over, increment turn and draw current board.
		turnCounter++;
		gameBoard->drawBoard();
	}
}


void Game::runAiGame()
{
	// Creates the AI pos mover
	AiOverwatch *watcher = new AiOverwatch(gameBoard);
	int turnCounter = 0;
	gameBoard->drawBoard();
	while (turnCounter < 9)
	{
		// Human player's move
		if (turnCounter%2 == 0)
		{
			int move = playerA->getMove();
			// Places player A's move 
			gameBoard->makeMove(playerA, move/10, move%10);
			// If a win achieved, go through the resetGame sequence
			if (gameBoard->checkWin(playerA->getPlayerPiece()))
			{
				resetGame(playerA, HAL9000, false, true);
				delete watcher;
				return;
			}
		}
		// Computer player's move
		else if (turnCounter%2 != 0)
		{
			// Gets move from the AiOverwatch class
			int move = watcher->minimax();
			gameBoard->makeMove(HAL9000, move/10, move%10);
			if (gameBoard->checkWin('O'))
			{
				resetGame(HAL9000, playerA, false, true);
				delete watcher;
				return;
			}
		}
		// Tie situation (no one wins)
		if (turnCounter == 8)
		{
			resetGame(playerA, HAL9000, true, true);
			delete watcher;
			return;
		}
		turnCounter++;
		gameBoard->drawBoard();
	}
}

// Sets other player's piece to the opposite
void Game::characterSelection()
{
	playerA->setCharPieceChoice();
	if (playerA->getPlayerPiece() == 'X')
	{
		playerB->setCharPiece('O');
	}
	else
	{
		playerB->setCharPiece('X');
	}
	return;
}


void Game::resetGame(Player *winningPlayer, Player *losingPlayer, bool tie, bool gameType)
{
	// If not tie, print victory, and if tie, print sadness
	if (!tie)
	{
		gameBoard->victoryBrag(winningPlayer);
		winningPlayer->updateWins();
	}
	else
	{
		gameBoard->tieSad();
	}
	gameBoard->clearBoard();

	// Check if play again
	bool play = playAgain();
	// If human game already played, start a new one if they want
	if ((play == true) && (gameType == false))
	{
		runHumanGame();
		return;
	}
	// If ai game already played, start a new one if they want
	else if ((play == true) && (gameType == true))
	{
		runAiGame();
		return;
	}
	// If they just want to go home, just let them...
	else
	{
		printFinalScore(winningPlayer, losingPlayer);
		mainMenu();
		return;
	}

}


bool Game::playAgain()
{
	char selection;
	std::cout << "Do you wish to play again?" << std::endl;
	std::cout << "Enter y/n: ";
	std::cin >> selection;
	switch(selection)
	{
		case 'y':
		case 'Y':
			return true;
		break;
		case 'n':
		case 'N':
			return false;
		break;
		default:	
			std::cout << "Invalid selection. Please be careful." << std::endl;
			playAgain();
	}
	return false;
}


void Game::printFinalScore(Player *winner, Player *loser)
{
	std::cout << "FINAL SCORES:" << std::endl;
	winner->printWins();
	loser->printWins();
	return;
}


Board* Game::getBoard()
{
	return gameBoard;
}


Ai* Game::getAi()
{
	return HAL9000;
}


Human* Game::getHuman()
{
	return playerA;
}

