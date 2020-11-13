// File: BoggleSolver.h
// Project: CBoggle
// Programmer: Philip Kempton
// First Version: 2020-11-13
// Description: This file contains function definitions for finding all words in a Boggle board.

#ifndef __BOGGLESOLVER_H__
#define __BOGGLESOLVER_H__

#include "BoggleBoard.h"
#include "WordDict.h"

// function declarations
void findWordsAtIndex(char board[BOARD_HEIGHT][BOARD_WIDTH], int visited[BOARD_HEIGHT][BOARD_WIDTH],
    int row, int col, char str[MAX_WORD_LEN], DictNode* head);
void solveBoggleBoard(char board[BOARD_HEIGHT][BOARD_WIDTH], DictNode* head);


#endif // !__BOGGLESOLVER_H__
