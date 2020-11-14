// File: BoggleSolver.c
// Project: CBoggle
// Programmer: Philip Kempton
// First Version: 2020-11-13
// Description: This file contains initializers for functions used to find all words in a Boggle board.

#include "BoggleSolver.h"

// Function: 
// Description: Finds and displays all words in a boggle board from a specific starting point.
// Parameters:
//    board:   the Boggle board.
//    visited: grid used to track which cells have been used in each possible word.
//    row:     row index for beginning of word.
//    col:     col index for beginning of word.
//    head:    head node of the word dictionary.
// Returns: n/a.
static void findWordsAtIndex(char board[BOARD_HEIGHT][BOARD_WIDTH], 
    int row, int col, char str[MAX_WORD_LEN], DictNode* head)
{
    if (board[row][col] != '\0')
    {
        str[strlen(str)] = board[row][col];
        board[row][col] = '\0';

        // display word if it exists in word dictionary.
        lowerCaseify(str);
        if (searchWordDict(head, str) == 1)
        {
            printf("%s\n", str);
        }

        // check the 8 adjacent cells of board[row][col].
        for (int currRow = row - 1; currRow <= row + 1 && currRow < BOARD_HEIGHT; currRow++)
        {
            for (int currCol = col - 1; currCol <= col + 1 && currCol < BOARD_WIDTH; currCol++)
            {
                if (currRow >= 0 && currCol >= 0)
                {
                    // all indices are valid and we haven't checked this cell yet.
                    // recursive call to check for longer words.
                    findWordsAtIndex(board, currRow, currCol, str, head);
                }
            }
        }

        // remove the character that was added and mark the spot as not-visited.
        board[row][col] = str[strlen(str) - 1];
        str[strlen(str) - 1] = '\0';
    }
}


// Function: solveBoggleBoard
// Description: Solves a Boggle board, finding and displaying all words that can be found in both a
//              Boggle board and a word dictionary.
// Parameters:
//    board: the Boggle board to solve.
//    head:  the dictionary.
// Returns: n/a.
void solveBoggleBoard(char board[BOARD_HEIGHT][BOARD_WIDTH], DictNode* head)
{
    // initialize an empty string to track current word being checked.
    char str[MAX_WORD_LEN] = { { '\0' } };

    // find and display all words found at each potential starting point.
    for (int row = 0; row < BOARD_HEIGHT; row++)
    {
        for (int col = 0; col < BOARD_WIDTH; col++)
        {
            findWordsAtIndex(board, row, col, str, head);
        }
    }
}