// File: WordDict.c
// Project: CBoggle
// Programmer: Philip Kempton
// First Version: 2020-11-12
// Description: This file contains function and struct declarations for the Word Dictionary.
//				This word dictionary was designed based on a Trie implementaion found here:
//				https://www.techiedelight.com/trie-implementation-insert-search-delete/

#ifndef __WORDDICT_H__
#define __WORDDICT_H__

#include <stdlib.h>
#include <stdio.h>

#define ALPHABET_SIZE 26 // 26 letters in English alphabet.
#define MAX_WORD_LEN 50 // arbitrarily assume max chars for max word length.

// represents a character node within the word dictionary.
typedef struct Node
{
	int isEndOfWord; // 1 if true, 0 otherwise.
	struct Node* characters[ALPHABET_SIZE]; // 1 ptr for each letter in alphabet.
} DictNode;

// function declarations.
DictNode* createWordDict(char* fileName);
void insertIntoWordDict(DictNode* head, char* word);
DictNode* getNewDictNode();
int searchWordDict(DictNode* head, char* word);
int hasChildren(DictNode* curr);
void clearWordDict(DictNode* curr);


#endif // !__WORDDICT_H__
