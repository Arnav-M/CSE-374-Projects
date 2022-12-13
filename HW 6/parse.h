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
 * Interface to parser/calculator for rational numbers
 */

#ifndef PARSE_H_
#define PARSE_H_

#include "./rational.h"

/* Return value of next expression on current input line.         */
/* (If errors are detected, a bogus number like 0/0 is returned.) */
Rational expr();

#endif  // PARSE_H_
