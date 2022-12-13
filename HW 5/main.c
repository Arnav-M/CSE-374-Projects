// Arnav Mathur
// CSE 374 HW 5
// 05/12/2022
// Converts number sequences to words by using a Trie with nodes that are
// linked. Starts an interactive session with the user on the terminal for
// the number sequences. The user can exit the session using 'exit'.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "trie.h"

#define MAX_LENGTH 100  // Maximum length of one line

Trie* createTrie(char* file);
void startIOSession(Trie* root);

int main(int argc, char* argv[]) {
    // Checks if arguments are correct
    if (argc != 2) {
        fprintf(stderr, "Two arguments are required.\n");
        exit(1);
    }
    // Creates the trie using the file
    char* file = argv[1];
    Trie* root = createTrie(file);

    // Runs the IO session and frees memory at the end
    if (root != NULL) {
        startIOSession(root);
        freeMem(root);
    }
    return 0;
}

// Creates the overall trie using the file, takes in the name of the file
// as a pointer. Returns a pointer to the tree
Trie* createTrie(char* file) {
    Trie* root;
    char line[MAX_LENGTH];
    char* buffer;
    FILE* f = fopen(file, "r");
    // Checks if file exists, gives error otherwise
    if (f == NULL) {
        fprintf(stderr, "File: %s was not found:\n", file);
        return NULL;
    } else {  // If file exists creates an empty trie then populates it
        root = createNode(NULL);
        while (fgets(line, MAX_LENGTH, f)) {
            buffer = malloc(sizeof(char) * (strlen(line) + 1));
            strncpy(buffer, line, sizeof(char) * (strlen(line) + 1));
            insert(root, buffer);  // Inserts values into the tree
        }
    }
    // Closes the file
    fclose(f);
    return root;
}

// Starts the IO session with the user, takes in the whole trie as a pointer
void startIOSession(Trie* root) {
    char stdin[MAX_LENGTH + 1];
    char prev[MAX_LENGTH + 1];

    printf("Enter \"exit\" to quit.\n");
    printf("Enter Key Sequence (or \"#\" for next word):\n");
    printf("> ");
    scanf("%s", stdin);  // Takes in user input

    while (strcmp(stdin, "exit") != 0) {
        // Prints values for "#"
        if (strncmp(stdin, "#", 1) == 0) {
            int len = sizeof(prev + strlen(prev));
            snprintf(prev + strlen(prev), len + 1, "#");
            printf("        %s", search(root, prev));
        } else {  // Prints values for the normal T9 values
            printf("        %s", search(root, stdin));
            snprintf(prev, strlen(stdin) + 1, "%s", stdin);
        }
        printf("Enter Key Sequence (or \"#\" for next word):\n");
        printf("> ");
        scanf("%s", stdin);
    }
}

