// File: Common.c
// Project: CBoggle
// Programmer: Philip Kempton
// First Version: 2020-11-13
// Description: This file common function initializers.

#include "Common.h"

// Function: lowerCaseify
// Description: turns all upper case chars in a string into the lower case equivalent.
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
        }
    }
}