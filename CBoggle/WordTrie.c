// File: WordTrie.c
// Project: CBoggle
// Programmer: Philip Kempton
// First Version: 2020-11-11
// Description: This file contains an implementation of a Trie structure for storing/retrieving strings.
//				This Trie implementation is modified from a pre-existing implementation found here:
//				https://www.techiedelight.com/trie-implementation-insert-search-delete/

#include "WordTrie.h"

// Function:  getNewTrieNode
// Description: Function that returns a new Trie node.
// Parameters: n/a.
// Returns: new Trie node.
TrieNode* getNewTrieNode()
{
	// malloc space for the new node and set isLeaf to false.
	TrieNode* node = (struct TrieNode*)malloc(sizeof(TrieNode));
	node->isLeaf = 0;

	// init all chars to Null.
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		node->character[i] = NULL;
	}
	return node;
}


// Function: insert
// Description: Iterative function to insert a string in Trie.
// Parameters:
//		head:	head node of the Trie to insert into.
//		str:	string to insert.
// Returns: n/a.
void insert(TrieNode* head, char* str)
{
	// start from head node.
	TrieNode* curr = head;
	while (*str)
	{
		// create a new node if path doesn't exist.
		if (curr->character[*str - 'a'] == NULL)
		{
			curr->character[*str - 'a'] = getNewTrieNode();
		}

		// go to next node.
		curr = curr->character[*str - 'a'];

		// increment character pntr.
		str++;
	}

	// mark current node as leaf.
	curr->isLeaf = 1;
}


// Function: search
// Description: Iterative function to search a string in Trie.
// Parameters:
//		head:	head node of the Trie to search.
//		str:	string to search for.
// Returns: 1 if string found, 0 otherwise.
int search(TrieNode* head, char* str)
{
	// return 0 if Trie is empty.
	if (head == NULL)
	{
		return 0;
	}

	// start at head node.
	TrieNode* curr = head;
	while (*str)
	{
		// go to next node.
		curr = curr->character[*str - 'a'];

		if (curr == NULL)
		{
			// reached end of path in Trie.
			return 0;
		}

		// move to next character.
		str++;
	}

	// if current node is a leaf and we have reached the end of the string, return 1.
	return curr->isLeaf;
}


// Function: hasChildren
// Description: Function to check if node has any children.
// Parameters:
//		curr:	node to check for children.
// Returns: 1 if has children, 0 otherwise.
int hasChildren(TrieNode* curr)
{
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		if (curr->character[i])
		{
			// child found.
			return 1;
		}
	}
	// no children found.
	return 0;
}


// Function: delete
// Description: Recursive function to delete a string in Trie.
// Parameters:
//		curr:	current node being checked.
//		str:	string to delete from Trie.
// Returns: 1 if deleted, 0 otherwise.
int delete(TrieNode** curr, char* str)
{
	if (*curr == NULL)
	{
		// Trie is empty... return 0
		return 0;
	}
	if (*str)
	{
		// end of string not yet reached.
		// recur for the node corresponding to next character in the string and if it returns 1, delete 
		// current node if it's non-leaf.
		if (*curr != NULL && (*curr)->character[*str - 'a'] != NULL &&
			delete(&((*curr)->character[*str - 'a']), str + 1) &&
			(*curr)->isLeaf == 0)
		{
			if (!hasChildren(*curr))
			{
				free(*curr);
				(*curr) = NULL;
				return 1;
			}
			else {
				return 0;
			}
		}
	}
	if (*str == '\0' && (*curr)->isLeaf)
	{
		// end of string reached.
		if (!hasChildren(*curr))
		{
			// current node is a leaf node and doesn't have any children, delete it.
			free(*curr);
			(*curr) = NULL;
			return 1;
		}
		else
		{
			// current node is a leaf and has children.
			// mark current node as non-leaf node (DON'T DELETE IT).
			// return 0 so parent nodes are not deleted.
			(*curr)->isLeaf = 0;
			return 0;
		}
	}
	return 0;
}