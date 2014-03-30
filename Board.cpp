//Board.cpp
#include "Board.h"
#include <iostream>
#include <stdlib.h>  // srand() and rand()
#include <time.h>  // time()

int flag =1;//special flag to trace the move of player,we only need the latest movement of player
//constructor
Board::Board()
{
	for(int i = 0; i<BOARD_SIZE; ++i)
	{
		for(int l = 0; l<BOARD_SIZE; ++l)
		{
			boardArray[i][l] = " ";
		}
	}

	for(int m = 0; m<VISUAL_BOARD_SIZE; ++m)
	{
		if(m%2 == 0)
		{
			for (int n = 0; n<VISUAL_BOARD_SIZE; ++n)
			{
				if (n%2 == 0)
				{
					visualBoardArray[m][n] = " ";
				}
				else
				{
					visualBoardArray[m][n] = "|";
				}
			}
		}
		else
		{
			for (int n = 0; n<VISUAL_BOARD_SIZE; ++n)
			{
				visualBoardArray[m][n] = "-";
			}
		}
	}
}


//destructor
Board::~Board()
{
	std::cout<<"Destructor run!";
}

//function to clean board
void Board::CleanBoard()
{
	for(int i = 0; i<BOARD_SIZE; ++i)
	{
		for(int l = 0; l<BOARD_SIZE; ++l)
		{
			boardArray[i][l] = " ";
		}
	}

	for(int m = 0; m<VISUAL_BOARD_SIZE; ++m)
	{
		if(m%2 == 0)
		{
			for (int n = 0; n<VISUAL_BOARD_SIZE; ++n)
			{
				if (n%2 == 0)
				{
					visualBoardArray[m][n] = " ";
				}
				else
				{
					visualBoardArray[m][n] = "|";
				}
			}
		}
		else
		{
			for (int n = 0; n<VISUAL_BOARD_SIZE; ++n)
			{
				visualBoardArray[m][n] = "-";
			}
		}
	}
	playerArray.clear();
	aiArray.clear();
	placeTaken.clear();
	flag = 1;
}

//function to print board
void Board::PrintBoard()
{
	for(int m = 0; m<VISUAL_BOARD_SIZE; ++m)
	{
		for (int n = 0; n<VISUAL_BOARD_SIZE; ++n)
		{
			if(n == VISUAL_BOARD_SIZE-1)
			{
				std::cout<<	visualBoardArray[m][n]<<"\n";
			}
			else
			{
				std::cout<<	visualBoardArray[m][n];
			}	
		}
	}
}

//check if anyone win the game
bool Board::CheckWinState()
{
	bool win=false;
	//if player only has 3 moves then check directly
	if (playerArray.size()==3)
	{
		int sum;
		sum = playerArray[0]+playerArray[1]+playerArray[2];
		if (sum == 15)
		{
			win = true;
			std::cout<<"You win!\n";
		}
	}
	//if player has 4 move check the possibilities
	else if(playerArray.size() == 4)
	{
		int sum[4];
		sum[0] = playerArray[0]+playerArray[1]+playerArray[2];
		sum[1] = playerArray[0]+playerArray[1]+playerArray[3];
		sum[2] = playerArray[0]+playerArray[2]+playerArray[3];
		sum[3] = playerArray[1]+playerArray[2]+playerArray[3];
		for(int i = 0; i<4;++i)
		{
			if(sum[i]==15)
			{
				win = true;
				std::cout<<"You win!\n";
			}
		}
	}
	//if player has 5 move check the possibilities
	else if(playerArray.size() == 5)
	{
		int sum[10];
		sum[0] = playerArray[0]+playerArray[1]+playerArray[2];
		sum[1] = playerArray[0]+playerArray[1]+playerArray[3];
		sum[2] = playerArray[0]+playerArray[1]+playerArray[4];
		sum[3] = playerArray[0]+playerArray[2]+playerArray[3];
		sum[4] = playerArray[0]+playerArray[2]+playerArray[4];
		sum[5] = playerArray[0]+playerArray[3]+playerArray[4];
		sum[6] = playerArray[1]+playerArray[2]+playerArray[3];
		sum[7] = playerArray[1]+playerArray[2]+playerArray[4];
		sum[8] = playerArray[1]+playerArray[3]+playerArray[4];
		sum[9] = playerArray[2]+playerArray[3]+playerArray[4];
		for(int i = 0; i<10;++i)
		{
			if(sum[i]==15)
			{
				win = true;
				std::cout<<"You win!\n";
			}
		}
	}
	//do the same thing for ai
	else if (aiArray.size()==3)
	{
		int sum;
		sum = aiArray[0]+aiArray[1]+aiArray[2];
		if (sum == 15)
		{
			win = true;
			std::cout<<"You lose!\n";
		}
	}
	else if(aiArray.size() == 4)
	{
		int sum[4];
		sum[0] = aiArray[0]+aiArray[1]+aiArray[2];
		sum[1] = aiArray[0]+aiArray[1]+aiArray[3];
		sum[2] = aiArray[0]+aiArray[2]+aiArray[3];
		sum[3] = aiArray[1]+aiArray[2]+aiArray[3];
		for(int i = 0; i<4;++i)
		{
			if(sum[i]==15)
			{
				win = true;
				std::cout<<"You lose!\n";
			}
		}
	}
	return win;
}

//update the board for printing
void Board::UpdateVisualBoard()
{
	for(int i = 0; i<BOARD_SIZE; ++i)
	{
		for (int l = 0; l<BOARD_SIZE; ++l)
		{
			visualBoardArray[i*2][l*2] = boardArray[i][l]; 
		}
	}
}

//transfer the position to 9 value
int Board::MagicTransfer(int x,int y)
{
	int result;
	if(x == 0)
	{
		if (y == 0)
		{
			result = 8;
		}
		else if (y == 1)
		{
			result = 1;
		}
		else if (y == 2)
		{
			result = 6;
		}
	}
	else if (x == 1)
	{
		if (y == 0)
		{
			result = 3;
		}
		else if (y == 1)
		{
			result = 5;
		}
		else if (y == 2)
		{
			result = 7;
		}
	}
	else if (x == 2)
	{
		if (y == 0)
		{
			result = 4;
		}
		else if (y == 1)
		{
			result = 9;
		}
		else if (y == 2)
		{
			result = 2;
		}
	}
	return result;
}


//void Board::MakeMove(bool player,int x,int y,int moveFlag)


//function to move
void Board::MakeMove(bool player,int x,int y)
{
	//if its player place "O"
	if(player == 1)
	{
		boardArray[x][y] = "O";
		UpdateVisualBoard();
		//add the move into player array
		playerArray.push_back(MagicTransfer(x,y));
		//also add the move into taken array
		placeTaken.push_back(MagicTransfer(x,y));
	}
	//if its ai place "X"
	else
	{
		boardArray[x][y] = "X";
		UpdateVisualBoard();
		//add the move into ai array
		aiArray.push_back(MagicTransfer(x,y));
		//also add the move into taken array
		placeTaken.push_back(MagicTransfer(x,y));
	}
}

//void Board::AIMove(int aiMoveFlag)



void Board::AIMove()
{
	//check the first move of player,if it's mid then take corner otherwise take mid
	if (playerArray.size() == 1)
	{
		if(playerArray[0] == 5)
		{
			srand ( (unsigned int)time(NULL) );
			int randomNum = rand()%4;
			if (randomNum==0)
			{
				//MakeMove(0,0,0,aiMoveFlag);
				MakeMove(0,0,0);
			}
			else if(randomNum==1)
			{
				//MakeMove(0,0,2,aiMoveFlag);
				MakeMove(0,0,2);
			}
			else if(randomNum==2)
			{
				//MakeMove(0,2,0,aiMoveFlag);
				MakeMove(0,2,0);
			}
			else if(randomNum==3)
			{
				//MakeMove(0,2,2,aiMoveFlag);
				MakeMove(0,2,2);
			}
		}
		else
		{
			//MakeMove(0,1,1,aiMoveFlag);
			MakeMove(0,1,1);
		}
	}
	//always block the move to prevent player from winning
	else
	{
		int targetPlace;//the value of the target place we need to place
		//base on the value we set to the board our target place is the subtract of first two player moves 
		targetPlace = 15-(playerArray[0]+playerArray[flag]);
		int xPos=0,yPos=0;
		//if the place has been taken choose another one
		for (size_t i=0;i < placeTaken.size();++i)
		{
			if (placeTaken[i]==targetPlace)
			{
				if (targetPlace<9)
				{
					targetPlace++;
					i =0;
				}
				else
				{
					targetPlace = 1;
					i = 0;
				}
			}
		}
		//transfer the value to place we need
		switch(targetPlace)
		{
		case 8:
			xPos = 0;
			yPos = 0;
			break;
		case 1:
			xPos = 0;
			yPos = 1;
			break;
		case 6:
			xPos = 0;
			yPos = 2;
			break;
		case 3:
			xPos = 1;
			yPos = 0;
			break;
		case 5:
			xPos = 1;
			yPos = 1;
			break;
		case 7:
			xPos = 1;
			yPos = 2;
			break;
		case 4:
			xPos = 2;
			yPos = 0;
			break;
		case 9:
			xPos = 2;
			yPos = 1;
			break;
		case 2:
			xPos = 2;
			yPos = 2;
			break;
		default:
			std::cout<<"Number of range!";
			break;
		}
		//MakeMove(0,xPos,yPos,aiMoveFlag);
		MakeMove(0,xPos,yPos);
		flag++;
	}
}