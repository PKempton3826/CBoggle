// File: BoggleBoard.c
// Project: CBoggle
// Programmer: Philip Kempton
// First Version: 2020-11-11
// Description: This file contains initializers for functions and constants for a Boggle game board.

#include "BoggleBoard.h"

// constant for the cube data for a Boggle game board.
// each array acts as a single cube.
const char* CUBE_DATA[CUBE_COUNT][CUBE_SIDE_COUNT] = {
    { "R", "I", "F", "O", "B", "X" },
    { "I", "F", "E", "H", "E", "Y" },
    { "D", "E", "N", "O", "W", "S" },
    { "U", "T", "O", "K", "N", "D" },
    { "H", "M", "S", "R", "A", "O" },
    { "L", "U", "P", "E", "T", "S" },
    { "A", "C", "I", "T", "O", "A" },
    { "Y", "L", "G", "K", "U", "E" },
    { "Qu", "B", "M", "J", "O", "A" },
    { "E", "H", "I", "S", "P", "N" },
    { "V", "E", "T", "I", "G", "N" },
    { "B", "A", "L", "I", "Y", "T" },
    { "E", "Z", "A", "V", "N", "D" },
    { "R", "A", "L", "E", "S", "C" },
    { "U", "W", "I", "L", "R", "G" },
    { "P", "A", "C", "E", "M", "D" }
};


// Function: newBoard
// Description: Populates a Boggle game board by 'randomly' rolling the cubes and then shuffling
//              them using the Fisher-Yates Shuffle algorithm.
// Parameters:
//      board:  the board to populate.
//  Returns: n/a.
void newBoard(char* board[BOARD_HEIGHT * BOARD_WIDTH])
{
    // roll the cubes.
    for (int i = 0; i < BOARD_HEIGHT * BOARD_WIDTH; i++)
    {
        board[i] = CUBE_DATA[i][rand() % CUBE_SIDE_COUNT];
    }

    // shuffle board (performs the Fisher Yates shuffle 3 times).
    char* buff;
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
