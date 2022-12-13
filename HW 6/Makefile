# Copyright ©2022 Hal Perkins.  All rights reserved.  Permission is
# hereby granted to students registered for University of Washington
# CSE 374 for use solely during Spring Quarter 2022 for purposes of
# the course.  No other use, copying, distribution, or modification
# is permitted without prior written consent. Copyrights for
# third-party components of this work must be honored.  Instructors
# interested in reusing these course materials should contact the
# author.

# Makefile for rational number calculator

calc: rational.o scan.o parse.o calc.o
	g++ -Wall -g -std=c++17 -o calc calc.o rational.o scan.o parse.o

rational.o: rational.cc rational.h
	g++ -Wall -g -std=c++17 -c rational.cc

scan.o: scan.cc token.h scan.h
	g++ -Wall -g -std=c++17 -c scan.cc

parse.o: parse.cc rational.h token.h scan.h
	g++ -Wall -g -std=c++17 -c parse.cc

calc.o: calc.cc rational.h token.h scan.h parse.h
	g++ -Wall -g -std=c++17 -c calc.cc

clean:
	rm -f *.o *~ calc
