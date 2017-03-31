CC=g++
CFLAGS=-I.

main: main.o game.o ai.o
	$(CC) -o main main.o game.o ai.o -I.
