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
 * Interactive calculator for expressions with rational numbers.
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include "./rational.h"
#include "./token.h"
#include "./scan.h"
#include "./parse.h"
using namespace std;

// print rational r followed by a newline
void prrat(Rational r) {
  cout << r.n() << "/" << r.d() << endl;
}

/* Read and print expressions until eof */
int main() {
  string input_line;
  cout << "Enter expressions with integer rational numbers (n/d) and" << endl;
  cout << "the operations +, -, *, and %.  One line per expression." << endl;
  cout << "Enter eof (cntrl-D) to stop." << endl;
  while (getline(cin, input_line)) {
    set_input(input_line);
    prrat(expr());
  }

  return EXIT_SUCCESS;
}
