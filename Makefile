CC=g++
CFLAGS=-I.

main: main.o Arr4.o Game.o AI.o
	$(CC) -o main main.o Arr4.o Game.o AI.o -I.
