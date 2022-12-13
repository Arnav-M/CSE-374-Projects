// Arnav Mathur
// CSE 374 HW 5
// 05/12/2022
// Contains supporting functions for the trie
// createNode, insert, search, convert, freeMem

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "trie.h"
#define CHILDREN 10  // Children nodes

// Creates a trie with null values
// Returns a pointer to the tree
Trie* createNode(char* word) {
    Trie *n = (Trie*) malloc(sizeof(Trie));
    n->word = word;
    for (int i = 0; i < CHILDREN; i++) {
        n->children[i] = NULL;
    }
    return n;
}

// Inserts the values of the T9 predictive text into the trie
void insert(Trie *root, char *word) {
    int digit;
    int i = 0;
    Trie* current = root;

    while (i < strlen(word) && (word[i] != '\0' && word[i] != '\n')) {
        digit = convert(word[i]);
        if (digit == -1) {
            return;
        } else {
            if (current->children[digit - 2] == NULL) {
                current->children[digit - 2] = createNode(NULL);
            }
            current = current->children[digit - 2];
        }
        i++;
    }
    if (current->word == NULL) {
        current->word = word;
    } else {
        while (current->children[8] != NULL) {
            current = current->children[8];
        }
        current->children[8] = createNode(word);
    }
}

// Searches the trie created for the user input
// Returns a pointer to the string referred to by the values of the T9 text
char* search(Trie *root, char* input) {
    // Checks for invalid input at the start
    if (root == NULL || input[0] == '#') {
        return "Invalid input \n";
    }

    Trie* cur = root;
    int character;

    // Searches the entire trie
    while (*input != '\0' && *input != '\n') {
        if (*input == '#') {
            // Checks for T9onyms
            if (cur->children[8] == NULL) {
                return "There are no more T9onyms\n";
            }
            cur = cur->children[8];
        } else {
            character = *input - '0' - 2;
            if (character < 0 || character > 7) {
                return "Invalid input \n";
            } else if (cur->children[character] == NULL) {
                return "Not found in current dictionary \n";
            }
            cur = cur->children[character];
        }
        input++;
    }
    if (cur->word == NULL) {
        return "Not found in current dictionary \n";
    }
    return cur->word;
}

// Converts the numbers from the T9 text into a string based on numbers
int convert(char letter) {
    int t9[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8,
    8, 8, 9, 9, 9, 9};
    if (letter == '#') {
        return 1;
    } else {
        return t9[letter - 'a'];
    }
}

// Frees up memory for an unused node
void freeMem(Trie* root) {
    for (int i = 0; i < CHILDREN; i++) {
        if (root->children[i] != NULL) {
        freeMem(root->children[i]);
        }
    }
    free(root->word);
    free(root);
}


