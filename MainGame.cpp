#include <iostream>
#include "Board.h"
#include <conio.h>  // _getch()


void main()
{
	//creat board
	Board gameBoard;
	gameBoard.PrintBoard();
	bool win = false;
	//int playerMoveFlag = 0;
	//int enemyMoveFlag = 0;

	//if no one wins, keep move
	while(win == false)
	{
		//if its draw ask player if need to start a new game
		if (gameBoard.placeTaken.size()>=9)
		{
			std::cout<<"Draw! Do you want to start another game? Enter 1 for yes, 0 for no.\n";
			int choice;
			std::cin>>choice;
			if (choice==1)
			{
				//initiate board for new game
				gameBoard.CleanBoard();
			}
			else
			{
				break;
			}
		}
		//a round start with player
		std::cout<<"Please choose a place to mark\n"
				 <<"1,2,3\n"
				 <<"4,5,6\n"
				 <<"7,8,9\n"
				 <<"Enter the number to place.";
		int num;
		//get the place player want to place
		std::cin>>num;
		int xPos = 0,yPos = 0;
		//transfer place into array position
		xPos = (num-1)/3;
		yPos = (num-1)%3;
		//make a move for player and show board
		gameBoard.MakeMove(1,xPos,yPos);
		//playerMoveFlag++;
		gameBoard.PrintBoard();
		//check if player wins
		win = gameBoard.CheckWinState();
		//gameBoard.AIMove(enemyMoveFlag);

		//ai move and print board then check if ai wins
		gameBoard.AIMove();
		//enemyMoveFlag++;
		gameBoard.PrintBoard();
		win = gameBoard.CheckWinState();
	}


	_getch();
}
