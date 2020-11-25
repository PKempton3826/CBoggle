// File: BoggleBoard.c
// Project: CBoggle
// Programmer: Philip Kempton
// First Version: 2020-11-11
// Description: This file contains initializers for functions and constants for a Boggle game board.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "BoggleBoard.h"

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

// Function: newBoard
// Description: Populates a Boggle game board by 'randomly' rolling the cubes and then shuffling
//              them using the Fisher-Yates Shuffle algorithm.
// Parameters:
//    board: the board to populate.
// Returns: n/a.
void newBoard(char board[BOARD_HEIGHT][BOARD_WIDTH])
{
    // roll the cubes
    for (int row = 0; row < BOARD_HEIGHT; row++)
    {
        for (int col = 0; col < BOARD_WIDTH; col++)
        {
            board[row][col] = CUBE_DATA[col + (BOARD_WIDTH * row)][rand() % CUBE_SIDE_COUNT];
        }
    }

    // shuffle the chars around (performs Fisher-Yates shuffle 3 times)
    const int NUM_SHUFFLES = 3; // number of times to do the shuffle
    for (int j = 0; j < NUM_SHUFFLES; j++)
    {
        for (int i = BOARD_HEIGHT * BOARD_WIDTH - 1; i > 0; i--)
        {
            // get current index for row and column
            int currRow = (int)(i / BOARD_WIDTH);
            int currCol = i % BOARD_WIDTH;

            // get a random index to swap with curr
            int randIndex = rand() % i;
            int randRow = randIndex / BOARD_WIDTH;
            int randCol = randIndex % BOARD_WIDTH;
            char buff = board[currRow][currCol];
            board[currRow][currCol] = board[randRow][randCol];
            board[randRow][randCol] = buff;
        }
    }
}

// Function:lowerCaseify
// Description: turns all upper case chars in a string into thier lower case equivalents.
// Parameters:
//    str: string to lower-caseify.
// Returns: n/a.
void lowerCaseify(char* str)
{
    char* curr = str;
    for (int i = 0; i < strlen(str); i++)
    {
        // lower caseify ass chars in string until we find a '\0'
        while (*curr != '\0')
        {
            if (*curr >= 'A' && *curr <= 'Z')
            {
                *curr = *curr + 32;
            }
            curr++;
        }
    }
}
