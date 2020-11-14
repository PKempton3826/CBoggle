// File: BoggleSolver.h
// Project: CBoggle
// Programmer: Philip Kempton
// First Version: 2020-11-13
// Description: This file contains function definitions for finding all words in a Boggle board.

#ifndef _BOGGLESOLVER_H_
#define _BOGGLESOLVER_H_

#include "BoggleBoard.h"
#include "WordDict.h"

// function declarations
void solveBoggleBoard(char board[BOARD_HEIGHT][BOARD_WIDTH], DictNode* head);


#endif // !_BOGGLESOLVER_H_
