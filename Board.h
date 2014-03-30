//Board.h
#pragma once
#include <iostream>
#include <string>
#include <vector>

//size of the game board and the board we print
const int BOARD_SIZE = 3;
const int VISUAL_BOARD_SIZE = 5;


class Board
{
	std::string boardArray[BOARD_SIZE][BOARD_SIZE];//the board for storing game info
	std::string visualBoardArray[VISUAL_BOARD_SIZE][VISUAL_BOARD_SIZE];//the board for printing
	std::vector<int> playerArray;//the array for storing player move
	std::vector<int> aiArray;//the array for storing ai move
	

public:
	std::vector<int> placeTaken;//the array for storing all places have been taken
	//constructor
	Board();
	//destructor
	~Board();

	//interface
	void CleanBoard();
	void PrintBoard();
	bool CheckWinState();
	//void MakeMove(bool player,int x,int y,int moveFlag);
	void MakeMove(bool player,int x,int y);
	void UpdateVisualBoard();
	int MagicTransfer(int x, int y);
	//void AIMove(int aiMoveFlag);
	void AIMove();
};