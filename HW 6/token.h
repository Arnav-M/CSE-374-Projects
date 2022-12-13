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
 * Interface for lexical tokens returned by calculator scanner
 */

#ifndef TOKEN_H_
#define TOKEN_H_

// lexical classes
enum lex_class {
  UNKNOWN,          // illegal or unknown character
  INT,              // integer constant
  PLUS,             // operator +
  MINUS,            // operator -
  TIMES,            // operator *
  DIV,              // operator %
  SLASH,            // slash to separate numerator/denominator
  LPAREN,           // (
  RPAREN,           // )
  EOL               // end of input line
};

// lexical token returned by scanner
struct token {
  lex_class kind;   // lexical class of the token
  int       ival;   // integer value if kind == INT (undefined otherwise)
};

#endif  // TOKEN_H_
