#include <iostream>
#include "human.h"
#include "player.h"

Human::Human()
{
	name = "Unnamed";
	numberOfWins = 0;
}


Human::Human(std::string hName)
{
	name = hName;
	numberOfWins = 0;
}


void Human::setCharPieceChoice()
{
	char piece;
	std::cout << "Choose a character " << name << "! (X or O): ";
	std::cin >> piece;

	switch (piece)
	{
		case 'O':
			playerPiece = piece;
			break;
		case 'X':
			playerPiece = piece;
			break;
		// Calling function again if invalid entry is given
		default: 
			std::cout << "Invalid character option. Try again: ";
			setCharPieceChoice();
	}

	std::cout << name << ", your character is: " << piece << std::endl;
}


int Human::getMove()
{
	// Arbitrary value(s) to begin the while loop
	int x = 0, y = 0;

	// Loop until a valid move is made (both x and y)
	while (y < 1 || y > 3 || x < 1 || x > 3)
	{
		std::cout << "Make your Move " << name << "!" << std::endl;
		std::cout << "Enter a x coordinate: ";
		std::cin >> y;
		std::cout << "Enter a y coordinate: ";
		std::cin >> x;
	}

	return (10*(x-1) + (y-1));
}

