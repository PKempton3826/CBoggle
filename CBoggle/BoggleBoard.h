// File: BoggleBoard.h
// Project: CBoggle
// Programmer: Philip Kempton
// First Version: 2020-11-11
// Description: This file contains declarations for functions and constants for a Boggle game board.

#ifndef __BOGGLEBOARD_H__
#define __BOGGLEBOARD_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// constants for the Boggle game board.
#define BOARD_WIDTH 4
#define BOARD_HEIGHT 4
#define CUBE_COUNT BOARD_WIDTH * BOARD_HEIGHT
#define CUBE_SIDE_COUNT 6
#define CUBE_STR_LEN 3

// constant declaration for the cube data.
const char* CUBE_DATA[CUBE_COUNT][CUBE_SIDE_COUNT];

// declaration for the newBoard function.
void newBoard(char* board[BOARD_HEIGHT * BOARD_WIDTH]);


#endif // !__BOGGLEBOARD_H__
