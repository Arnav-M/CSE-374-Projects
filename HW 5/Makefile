# Arnav Mathur
# CSE 374 HW 5
# 05/12/2022
# This makefile compiles main.c and trie.c and creates the executable file - t9

all: t9

t9: main.o trie.o
	gcc -Wall -std=c11 -o t9 main.o trie.o

main.o: main.c trie.h
	gcc -Wall -std=c11 -c main.c

trie.o: trie.c trie.h
	gcc -Wall -std=c11 -c trie.c

clean:
	rm -f *.o output *~ 