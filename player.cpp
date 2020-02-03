#include <iostream>
#include "player.h"


void Player::updateWins()
{
	numberOfWins++;
}


void Player::printWins()
{
	std::cout << name << " won: " << numberOfWins << " times." << std::endl;
}


void Player::setName(std::string playerName)
{
	name = playerName;
}


void Player::setCharPiece(char piece)
{
	playerPiece = piece;
	std::cout << name << ", your character is: " << piece << std::endl;
}


char Player::getPlayerPiece()
{
	return playerPiece;
}


std::string Player::getName()
{
	return name;
}


int Player::getNumberOfWins()
{
	return numberOfWins;
}
