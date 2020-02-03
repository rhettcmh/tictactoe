#ifndef TEST_SCRIPT
#define TEST_SCRIPT
#include "board.h"
#include "game.h"

class TestScript
{
public:
	// Default test constructor
	TestScript();
	// Runs the tests
	void runTests();
	// Checks if tie success
	void tieTest();
	// Checks is a position is free
	void isFreeTest();
	// Checks if a move is cleared
	void clearMoveTest();
	// Checks if the gameboard is cleared
	void clearBoardTest();
	// Checks all types of win positions
	void checkWinTest();
	

private:
	Board *testBoard;
};

#endif // TEST_SCRIPT