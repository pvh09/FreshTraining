
CC = gcc
INC = -I ./inc
SRC = ./src/*.c

all: main
	./main

main: main.o gemtek_mahlib.a
	$(CC) main.o -o main -L./lib -l:gemtek_mahlib.a -lm

main.o: main.c
	$(CC) -c main.c $(INC)

gemtek_mahlib.a: gemtek_mathlib.o
	ar rcs ./lib/gemtek_mahlib.a gemtek_mathlib.o

gemtek_mathlib.o: $(SRC) 
	$(CC) -c $(SRC) $(INC)

clean:
	rm -rf main *.o

running: all main clean



