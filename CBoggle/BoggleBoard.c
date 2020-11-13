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
void newBoard(char board[BOARD_HEIGHT * BOARD_WIDTH])
{
    // roll the cubes.
    for (int i = 0; i < BOARD_HEIGHT * BOARD_WIDTH; i++)
    {
        board[i] = CUBE_DATA[i][rand() % CUBE_SIDE_COUNT];
    }

    // shuffle board (performs the Fisher Yates shuffle 3 times).
    char buff;
    const int NUM_SHUFFLES = 3;
    for (int j = 0; j < NUM_SHUFFLES; j++)
    {
        for (int i = BOARD_HEIGHT * BOARD_WIDTH - 1; i > 0; i--)
        {
            buff = board[i];
            int randIndex = rand() % i;
            board[i] = board[randIndex];
            board[randIndex] = buff;
        }
    }
}
