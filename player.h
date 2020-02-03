#ifndef PLAYER_H
#define PLAYER_H

// ABSTRACT CLASS
class Player
{
public:
	/* ----- WIN ACCESSOR AND MODIFIER ----- */ 

	// First update wins increments the win counter at the end of each round 
	void updateWins();
	
	// Second prints out each player's number of wins
	void printWins();


	/* ----- SETTERS ----- */ 

	// Sets the player's name
	void setName(std::string playerName);
	
	// Sets the player's gamepiece X/O
	void setCharPiece(char piece);

	// Virtual function for the first player to choose gamepiece (X/O?)
	virtual void setCharPieceChoice() = 0;


	/* ----- GETTERS ----- */ 
	
	// Virtual function that gets the move from Human and Ai Player
	virtual int getMove() = 0;

	// Self explanatory.
	char getPlayerPiece();
	std::string getName();
	int getNumberOfWins();

protected:
	std::string name;
	char playerPiece;
	int numberOfWins;
};

#endif // PLAYER_H