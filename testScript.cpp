#include <iostream>
#include "testScript.h"
#include "game.h"
#include "board.h"	

TestScript::TestScript() 
{
	testBoard = new Board();
	//testGame = new Game(testBoard);
}


void TestScript::runTests()
{
	tieTest();
	isFreeTest();
	clearMoveTest();
	clearBoardTest();
	checkWinTest();
}


void TestScript::tieTest()
{
	// Tie situation
	testBoard->gameStore[0][0] = 'X';
	testBoard->gameStore[0][1] = 'O';
	testBoard->gameStore[0][2] = 'X';
	testBoard->gameStore[1][0] = 'O';
	testBoard->gameStore[1][1] = 'O';
	testBoard->gameStore[1][2] = 'X';
	testBoard->gameStore[2][0] = 'X';
	testBoard->gameStore[2][1] = 'X';
	testBoard->gameStore[2][2] = 'O';

	if (!testBoard->checkWin('X') && !testBoard->checkWin('O'))
	{
		std::cout << "TIE TEST SUCCESS!" << std::endl;
	}
	else
	{
		std::cout << "TIE TEST FAIL" << std::endl;
	}
}


void TestScript::isFreeTest()
{
	// Clears two spots and checks if they are clear with isFree
	testBoard->gameStore[2][2] = ' ';
	testBoard->gameStore[0][2] = ' ';
	if (testBoard->isFree(2,2) && testBoard->isFree(0,2))
	{
		std::cout << "IS FREE TEST SUCCESS!" << std::endl;
	}
	else
	{
		std::cout << "IS FREE TEST FAIL" << std::endl;
	}
}


void TestScript::clearMoveTest()
{
	// Uses clearMove to check spots
	testBoard->clearMove(0,0);
	testBoard->clearMove(1,2);

	if (testBoard->isFree(0,0) && testBoard->isFree(1,2))
	{
		std::cout << "CLEAR MOVE TEST SUCCESS!" << std::endl;
	}
	else
	{
		std::cout << "CLEAR MOVE TEST FAIL" << std::endl;
	}
}

void TestScript::clearBoardTest()
{
	testBoard->clearBoard();
	// Check if every move is empty
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (!testBoard->isFree(i,j))
			{
				std::cout << "CLEAR BOARD TEST FAIL" << std::endl;
				return;
			}
		}
	}
	std::cout << "CLEAR BOARD TEST SUCCESS!" << std::endl;	
}

void TestScript::checkWinTest()
{
	// Check forward Diagonal
	testBoard->gameStore[0][0] = 'X';
	testBoard->gameStore[0][1] = 'O';
	testBoard->gameStore[0][2] = 'O';
	testBoard->gameStore[1][1] = 'X';
	testBoard->gameStore[1][2] = 'O';
	testBoard->gameStore[2][2] = 'X';

	if (testBoard->checkWin('X'))
	{
		std::cout << "FORWARD DIAGONAL CHECK SUCCESS!" << std::endl;
	}
	else
	{
		std::cout << "FORWARD DIAGONAL TEST FAIL" << std::endl;
	}

	// Check Rows
	testBoard->gameStore[0][0] = 'O';
	testBoard->gameStore[0][1] = 'O';
	testBoard->gameStore[0][2] = 'O';
	testBoard->gameStore[1][0] = 'X';
	testBoard->gameStore[1][1] = 'X';
	testBoard->gameStore[1][2] = 'O';
	testBoard->gameStore[2][2] = 'X';

	if (testBoard->checkWin('O'))
	{
		std::cout << "ROW CHECK SUCCESS!" << std::endl;
	}
	else
	{
		std::cout << "ROW TEST FAIL" << std::endl;
	}

	// Check Columns
	testBoard->gameStore[0][0] = 'O';
	testBoard->gameStore[0][1] = 'X';
	testBoard->gameStore[0][2] = 'O';
	testBoard->gameStore[1][0] = 'X';
	testBoard->gameStore[1][1] = 'X';
	testBoard->gameStore[1][2] = 'O';
	testBoard->gameStore[2][2] = 'O';

	if (testBoard->checkWin('O'))
	{
		std::cout << "COLUMN CHECK SUCCESS!" << std::endl;
	}
	else
	{
		std::cout << "COLUMN TEST FAIL" << std::endl;
	}

	// Check Backward Diagonal
	testBoard->gameStore[0][0] = 'O';
	testBoard->gameStore[0][1] = 'X';
	testBoard->gameStore[0][2] = 'O';
	testBoard->gameStore[1][0] = 'X';
	testBoard->gameStore[1][1] = 'O';
	testBoard->gameStore[1][2] = 'X';
	testBoard->gameStore[2][0] = 'O';
	testBoard->gameStore[2][2] = 'X';

	if (testBoard->checkWin('O'))
	{
		std::cout << "BACK DIAGONAL CHECK SUCCESS!" << std::endl;
	}
	else
	{
		std::cout << "BACK DIAGONAL TEST FAIL" << std::endl;
	}

	testBoard->clearBoard();
}
