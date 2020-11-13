// File: BoggleBoard.c
// Project: CBoggle
// Programmer: Philip Kempton
// First Version: 2020-11-11
// Description: This file contains initializers for functions and constants for a Boggle game board.

#include "BoggleBoard.h"

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

    // shuffle board (performs the Fisher Yates shuffle 3 times).
    char buff; // temp buffer for shuffling
    const int NUM_SHUFFLES = 3; // number of times to do the shuffle

    // 
    int randIndex;
    int randRow;
    int randCol;
    int currRow;
    int currCol;
    for (int j = 0; j < NUM_SHUFFLES; j++)
    {
        for (int i = BOARD_HEIGHT * BOARD_WIDTH - 1; i > 0; i--)
        {
            // get current index for row and column
            currRow = (int)(i / BOARD_WIDTH);
            currCol = i % BOARD_WIDTH;

            // get a random index to swap with curr
            randIndex = rand() % i;
            randRow = (int)(randIndex / BOARD_WIDTH);
            randCol = randIndex % BOARD_WIDTH;
            buff = board[currRow][currCol];
            board[currRow][currCol] = board[randRow][randCol];
            board[randRow][randCol] = buff;
        }
    }
}
