/*
Arnav Mathur
4/26/2022
Assignment 4
gasp.c
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Constants
#define MAX_LINES 500
#define KEYWORD_LENGTH 100

// Function Declaration
int process_file(int fileIndex, char *argv[]);

/* Main function
   Produces error if less than 3 arguments are provided.
   Returns -1 if error is present.
   Cycles through files to find sentences with the keyword provided. 
*/
int main(int argc, char *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Less than three arguments passed\n");
    return -1;
  }

  for (int i = 2; i < argc; i++) {
    process_file(i, argv);
  }
  return 0;
}

/* Process_file function
   Checks if file exists, if file does not exist produces error message.
   Returns -1 if file does not exist.
   If file exists, goes through lines in the file to find the keyword provided,
   if such a line exists it prints the line on the terminal.
   Is case-sensitive.
*/
int process_file(int fileIndex, char *argv[]) {
  FILE *file = fopen(argv[fileIndex], "r");  // pointer to file
  if (file == NULL) {
    fprintf(stderr, "%s - File does not exist.\n", argv[fileIndex]);
    return -1;
  } else {
    char line[MAX_LINES];  // stores all the lines in the file
    while (fgets(line, MAX_LINES, file)) {
      char temp[MAX_LINES];  // stores a temporary line
      char keyword[KEYWORD_LENGTH];  // stores the keyword
      strncpy(temp, line, MAX_LINES);
      strncpy(keyword, argv[1], KEYWORD_LENGTH);

      // Matches keyword with the line and prints the line if it matches.
      if (strstr(temp, keyword) != NULL) {
        printf("%s: %s", argv[fileIndex], line);
      }
    }
  }
  fclose(file);
  return 0;
}
