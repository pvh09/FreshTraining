CC = gcc
INC = -I ./inc
SRC = ./src/*.c
array: main.o array.o
	$(CC) array.o main.o -o run

main.o: main.c
	$(CC) -c main.c $(INC)

array.o: $(SRC) 
	$(CC) -c $(SRC) $(INC)

clean:
	rm -rf run *.o

run: array
	./run

running: array run clean

memory: main.c
	$(CC) main.c $(SRC) $(INC) -g -std=c11 -lm -o debug

debug: memory
	 valgrind --track-origins=yes --leak-check=full ./debug

debug_gdb: main.c $(SRC)
	$(CC) $(INC) main.c $(SRC) -o gdb_debug -g
	gdb ./gdb_debug
	rm -rf gdb_debug
