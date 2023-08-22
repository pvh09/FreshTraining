CC = gcc
INC = -I ./inc
SRC = ./src/*.c
matrix: main.o matrix.o
	$(CC) matrix.o main.o -o run

main.o: main.c
	$(CC) -c main.c $(INC)

matrix.o: $(SRC) 
	$(CC) -c $(SRC) $(INC)

clean:
	rm -rf run *.o

run: matrix
	./run

running: matrix run clean

memory: main.c
	$(CC) main.c $(SRC) $(INC) -g -std=c11 -lm -o debug

debug: memory
	 valgrind --track-origins=yes --leak-check=full ./debug
