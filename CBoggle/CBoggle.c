// File: CBoggle.c
// Project: CBoggle
// Programmer: Philip Kempton
// First Version: 2020-11-11
// Description: This file contains main() for the CBoggle application.  This application allows for
//              the creation and shuffling of a Boggle game board.  Additionally, this application
//              automatically finds and displays all English words found on a Boggle game board.

#include "BoggleBoard.h"

// declaration for function to display a Boggle board.
void displayBoard(char* board[BOARD_HEIGHT * BOARD_WIDTH]);

int main()
{
    // seed rand with curr time.
    srand((unsigned int)time(0));

    // initialize Boggle board.
    char* board[BOARD_HEIGHT * BOARD_WIDTH];
    newBoard(board);
    
    // enter application running loop.
    char c = '1';
    do
    {
        // clear screen and display options for the user.
        system("cls");
        printf("1. Shuffle Board\n");
        printf("2. Find Words\n");
        printf("3. Exit\n\n");

        // display the current game board for the user and wait for input.
        displayBoard(board);
        c = getch(stdin);

        switch (c)
        {
        case '2':
            // user pressed '2'.
            // find all words and display them for the user.
            printf("Not implemented\n\n");
            printf("Press any key for new board...\n");
            getch(stdin);
            // intentional fallthrough.
        case '1':
            // user pressed '1'.
            // get a new Boggle board.
            newBoard(board);
            break;

            // lack of Default case is intentional.
            // this will cause the input to be ignored as user entered an invalid option.
        }
    } while (c != '3');
    // user pressed '3'.
    // Exit application.
}


// Function: displayBoard
// Description: Displays a Boggle board in the console window.
// Parameters: 
//      board:  The Boggle board to display.
// Returns: n/a.
void displayBoard(char* board[BOARD_HEIGHT * BOARD_WIDTH])
{
    for (int i = 0; i < BOARD_HEIGHT * BOARD_WIDTH; i++)
    {
        printf(" %-2s", board[i]);
        if (i % BOARD_WIDTH == (BOARD_WIDTH - 1))
        {
            printf("\n");
        }
        else
        {
            printf(" | ");
        }
    }
    printf("\n");
}