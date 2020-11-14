// File: WordDict.h
// Project: CBoggle
// Programmer: Philip Kempton
// First Version: 2020-11-12
// Description: This file contains function and struct declarations for the Word Dictionary.
//              This word dictionary was designed based on a Trie implementaion found here:
//              https://www.techiedelight.com/trie-implementation-insert-search-delete/

#ifndef _WORDDICT_H_
#define _WORDDICT_H_

#define ALPHABET_SIZE 26 // 26 letters in English alphabet.

// represents a character node within the word dictionary.
typedef struct Node
{
    int isEndOfWord; // 1 if true, 0 otherwise.
    struct Node* characters[ALPHABET_SIZE]; // 1 ptr for each letter in alphabet.
} DictNode;

// function declarations.
DictNode* createWordDict(char* fileName);
int searchWordDict(DictNode* head, char* word);
void clearWordDict(DictNode* curr);

#endif // !_WORDDICT_H_
