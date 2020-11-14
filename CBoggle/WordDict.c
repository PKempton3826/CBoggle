// File: WordDict.c
// Project: CBoggle
// Programmer: Philip Kempton
// First Version: 2020-11-12
// Description: This file contains function initializers for the Word Dictionary.
//              This word dictionary was designed based on a Trie implementaion found here:
//              https://www.techiedelight.com/trie-implementation-insert-search-delete/

#include <stdlib.h>
#include <stdio.h>
#include "WordDict.h"
#include "BoggleBoard.h"

// Function: getNewDictNode
// Description: creates a new word dictionary node.
// Parameters: n/a.
// Returns: new word dictionary node ptr.
static DictNode* getNewDictNode(void)
{
    // malloc space for new node and mark it as non-endOfWord.
    DictNode* node = (struct DictNode*)calloc(1, sizeof(DictNode));
    if (node != NULL)
    {
        node->isEndOfWord = 0;
    }
    return node;
}


// Function: insertIntoWordDict
// Description: inserts a word into a word dictionary.
// Parameters:
//    head: head ptr of the word dictionary to insert into.
//    word: the word to insert.
// Returns: n/a.
static void insertIntoWordDict(DictNode* head, const char* word)
{
    // start at head.
    DictNode* curr = head;

    // put each character of the word into the word dictionary if it doesn't already exist.
    while (*word != NULL)
    {
        if (curr->characters[*word - 'a'] == NULL)
        {
            // character is not currently in place in the word dict, so add it in.
            curr->characters[*word - 'a'] = getNewDictNode();
        }
        // move to next character.
        curr = curr->characters[*word - 'a'];
        word++;
    }
    // all characters of word have been inserted.
    curr->isEndOfWord = 1;
}


// Function: hasChildren
// Description: checks if a word dictionary node has any children nodes (non-NULLs).
// Parameters:
//    curr: node to check for presence of children.
// Returns: 1 if node has children, 0 otherwise.
static int hasChildren(DictNode* curr)
{
    // check each character node.
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (curr->characters[i] != NULL)
        {
            // child found.
            return 1;
        }
    }
    return 0;
}


// Function: CreateWordDict
// Description: creates a new word dict from a file.
// Parameters:
//    fileName: filename for list of words.
// Returns: head ptr to the new word dictionary.
DictNode* createWordDict(const char* fileName)
{
    DictNode* head = NULL;
    char word[MAX_WORD_LEN];
    FILE* fp = NULL;
    if (fopen_s(&fp, fileName, "r") == 0)
    {
        // file opened successfully, setup the head node and put all words into the dictionary.
        head = getNewDictNode();
        while (fgets(word, MAX_WORD_LEN - 1, fp) != NULL)
        {
            // got a word, strip off the '\n' and make the word lowercase.
            if (word[strlen(word) - 1] == '\n')
            {
                word[strlen(word) - 1] = '\0';
            }
            lowerCaseify(word);
            
            // insert word into the dictionary.
            insertIntoWordDict(head, word);
        }
    }
    return head;
}


// Function: search
// Description: searches a word dictionary for the presence of a word.
// Parameters:
//    head: head node of the word dictionary to search within.
//    str:  str to search for.
// Returns: 1 if word is found, 0 otherwise.
int searchWordDict(DictNode* head, const char* word)
{
    // sanity check incase word dictionary is empty.
    if (head == NULL)
    {
        return 0;
    }
    
    // start at head node and check for existence of each character in the word dictionary.
    DictNode* curr = head;
    while (*word)
    {
        // move to next node.
        // if it is NULL, word doesn't exist in dictionary.
        curr = curr->characters[*word - 'a'];
        if (curr == NULL)
        {
            return 0;
        }
        word++;
    }
    return curr->isEndOfWord;
}


// Function: clear
// Description: frees all malloc'd space in a word dictionary.
// Parameters:
//    curr: current node being deleted.
// Returns: n/a.
void clearWordDict(DictNode* curr)
{
    if (curr != NULL)
    {
        // current node has been malloc'd.
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            // check if curr node has any children.
            if (curr->characters[i] != NULL)
            {
                // child found, recursive call to free the child node first.
                clearWordDict(curr->characters[i]);
            }
        }
        // free space for this node.
        free(curr);
    }
}