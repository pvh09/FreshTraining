CC = gcc
INC = -I ./inc
SRC = ./src/*.c
LIB = ./lib

all: main
	./main

main: main.o libgemtek_mahlib.so
	$(CC) main.o -o main -L$(LIB) -lgemtek_mahlib -lm -Wl,-rpath,$(LIB)

main.o: main.c
	$(CC) -c main.c $(INC)

libgemtek_mahlib.so: gemtek_mathlib.o
	$(CC) -shared -o $(LIB)/libgemtek_mahlib.so gemtek_mathlib.o 

gemtek_mathlib.o: $(SRC) 
	$(CC) -c $(SRC) $(INC) -fPIC

clean:
	rm -rf main *.o

running: all main clean