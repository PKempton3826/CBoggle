// File: WordTrie.h
// Project: CBoggle
// Programmer: Philip Kempton
// First Version: 2020-11-11
// Description: This file contains an declarations for constants, structs, and functions for a Trie structure.
//				This Trie implementation is modified from a pre-existing implementation found here:
//				https://www.techiedelight.com/trie-implementation-insert-search-delete/

#ifndef __WORDTRIE_H__
#define __WORDTRIE_H__

#include <stdlib.h>

// define alphabet size size.
#define ALPHABET_SIZE 26

// Struct for a Trie node.
typedef struct Trie
{
	int isLeaf;	// 1 if true, 0 otherwise.
	struct Trie* character[ALPHABET_SIZE];
} TrieNode; 

// Function declarations
TrieNode* getNewTrieNode(); // create new Trie node.
void insert(TrieNode* head, char* str); // insert into a Trie.
int search(TrieNode* head, char* str); // search within a Trie.
int hasChildren(TrieNode* curr); // check if a Trie node has child nodes.
int delete(TrieNode** curr, char* str); // delete a node from a Trie.


#endif // !__WORDTRIE_H__