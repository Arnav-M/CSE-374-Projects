// Arnav Mathur
// CSE 374 HW 5
// 05/12/2022
// Header file for trie.c

#ifndef TRIE_H
#define TRIE_H

typedef struct Trie {
    char* word;
    struct Trie *children[10];
} Trie;

Trie* createNode(char* word);
void insert(Trie* root, char* word);
char* search(Trie* root, char* word);\
int convert(char letter);
void freeMem(Trie* root);

#endif  // TRIE_H
