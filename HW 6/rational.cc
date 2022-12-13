// Arnav Mathur
// CSE 374 HW 7
// 06/02/2022
// Helper function for the Rational type, takes in Rational numbers and does
// calculations in calc.cc. Does addition, subtraction, multiplication,
// division of Rational fractions and numbers.

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
 * Implementation of rational number type
 */

#include "./rational.h"
#include <cmath>

// Greatest common divisor helper function
int gcd(int num1, int num2);

/*------------CONSTRUCTORS------------*/
// Rational type: 0/1
Rational::Rational() {
    num = 0;
    denom = 1;
}

// Rational type: n/1
Rational::Rational(int n) {
    num = n;
    denom = 1;
}

// Rational type n/d
Rational::Rational(int n, int d) {
    num = n;
    denom = d;
}
/*------------------------------------ */

// Returns numerator in lowest fraction.
// Takes absolute value of denominator.
int Rational::n() const {
    if (denom == 0) {
        return num;
    } else if (denom < 0) {
        return -1 * (num / gcd(num, denom));
    } else {
        return num / gcd(num, denom);
    }
}

// Returns denominator in lowest fraction.
// Takes absolute value of denominator.
int Rational::d() const {
    if (denom == 0) {
        return denom;
    } else if (denom < 0) {
        return -1 * (denom / gcd(num, denom));
    } else {
        return denom / gcd(num, denom);
    }
}

// Returns greatest common divisor of two numbers.
// Implemented to work with Rational numbers using absolute values.
int gcd(int num1, int num2) {
    if (num1 == 0) {
        return num2;
    } else if (num2 == 0) {
        return num1;
    } else if (num1 == num2) {
        return num1;
    } else if (num1 > num2) {
        return gcd(abs(num1) - abs(num2), abs(num2));
    } else {
        return gcd(abs(num1), abs(num2) - abs(num1));
    }
}

// Calculates this + other
Rational Rational::plus(Rational other) const {
    int num_plus = (num * other.denom) + (denom * other.num);
    int denom_plus = denom * other.denom;
    return Rational(num_plus, denom_plus);
}

// Calcultes this - other
Rational Rational::minus(Rational other) const {
    int num_minus = (num * other.denom) - (denom * other.num);
    int denom_minus = denom * other.denom;
    return Rational(num_minus, denom_minus);
}

// Calculates this * other
Rational Rational::times(Rational other) const {
    int num_times = num * other.num;
    int denom_times = denom * other.denom;
    return Rational(num_times, denom_times);
}

//  Calculates this / other
Rational Rational::div(Rational other) const {
    int num_div = num * other.denom;
    int denom_div = denom * other.num;
    return Rational(num_div, denom_div);
}
