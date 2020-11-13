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

// constant for the cube data for a Boggle game board.
// each array acts as a single cube.
static const char CUBE_DATA[CUBE_COUNT][CUBE_SIDE_COUNT] = {
    { 'R', 'I', 'F', 'O', 'B', 'X' },
    { 'I', 'F', 'E', 'H', 'E', 'Y' },
    { 'D', 'E', 'N', 'O', 'W', 'S' },
    { 'U', 'T', 'O', 'K', 'N', 'D' },
    { 'H', 'M', 'S', 'R', 'A', 'O' },
    { 'L', 'U', 'P', 'E', 'T', 'S' },
    { 'A', 'C', 'I', 'T', 'O', 'A' },
    { 'Y', 'L', 'G', 'K', 'U', 'E' },
    { 'Q', 'B', 'M', 'J', 'O', 'A' },
    { 'E', 'H', 'I', 'S', 'P', 'N' },
    { 'V', 'E', 'T', 'I', 'G', 'N' },
    { 'B', 'A', 'L', 'I', 'Y', 'T' },
    { 'E', 'Z', 'A', 'V', 'N', 'D' },
    { 'R', 'A', 'L', 'E', 'S', 'C' },
    { 'U', 'W', 'I', 'L', 'R', 'G' },
    { 'P', 'A', 'C', 'E', 'M', 'D' }
};

// declaration for the newBoard function.
void newBoard(char board[BOARD_HEIGHT][BOARD_WIDTH]);

#endif // !__BOGGLEBOARD_H__
