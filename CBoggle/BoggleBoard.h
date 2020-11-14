// File: BoggleBoard.h
// Project: CBoggle
// Programmer: Philip Kempton
// First Version: 2020-11-11
// Description: This file contains declarations for functions and constants for a Boggle game board.

#ifndef _BOGGLEBOARD_H_
#define _BOGGLEBOARD_H_

// constants for the Boggle game board.
#define BOARD_WIDTH 4
#define BOARD_HEIGHT 4
#define CUBE_COUNT BOARD_WIDTH * BOARD_HEIGHT
#define CUBE_SIDE_COUNT 6
#define CUBE_STR_LEN 3
#define MAX_WORD_LEN 50 // arbitrarily assume max chars for max word length.

// declaration for the newBoard function.
void newBoard(char board[BOARD_HEIGHT][BOARD_WIDTH]);
void lowerCaseify(char* str);

#endif // !_BOGGLEBOARD_H_
