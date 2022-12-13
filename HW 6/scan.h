/*
 * Copyright ©2022 Hal Perkins.  All rights reserved.  Permission is
 * hereby granted to students registered for University of Washington
 * CSE 374 for use solely during Spring Quarter 2022 for purposes of
 * the course.  No other use, copying, distribution, or modification
 * is permitted without prior written consent. Copyrights for
 * third-party components of this work must be honored.  Instructors
 * interested in reusing these course materials should contact the
 * author.
 */

/*
 * Interface to scanner for rational number calculator
 */

#ifndef SCAN_H_
#define SCAN_H_

#include <string>
#include "./token.h"
using namespace std;

// Next unprocessed token on current input line.
// Undefined if set_input has not been called.
extern token next_tok;

// Advance next_tok to next token on current input line, if any.
// If next_tok.kind == EOL on input, do nothing.
// pre: set_input has been called.
void scan();

// Set input line to new_line and advance next_tok to the first token
// in that new line (which might be EOL if the line is empty).
void set_input(string new_line);

#endif  // SCAN_H_
