# CC = gcc
# INC = -I ./inc
# SRC = ./src/*.c
# morse_code: main.o morse_code.o
# 	$(CC) morse_code.o main.o -o run

# main.o: main.c
# 	$(CC) -c main.c $(INC)

# morse_code.o: $(SRC) 
# 	$(CC) -c $(SRC) $(INC)

# clean:
# 	rm -rf run *.o

# run: morse_code
# 	./run

# running: morse_code run clean

# memory: main.c
# 	$(CC) main.c $(SRC) $(INC) -g -std=c11 -lm -o debug

# debug: memory
# 	 valgrind --track-origins=yes --leak-check=full ./debug

# debug_gdb: main.c $(SRC)
# 	$(CC) $(INC) main.c $(SRC) -o gdb_debug -g
# 	gdb ./gdb_debug
# 	rm -rf gdb_debug


CC = gcc
INC = -I./inc
SRC = ./src/*.c

all: run clean

run: main
	./main

main: main.c $(SRC)
	$(CC) $(INC) main.c $(SRC) -o main

debug_memory: main.c $(SRC)
	$(CC) $(INC) main.c $(SRC) -std=c11 -lm -o debug
	valgrind --track-origins=yes --leak-check=full ./debug
	rm -rf debug

debug_gdb: main.c $(SRC)
	$(CC) $(INC) main.c $(SRC) -o gdb_debug -g
	gdb ./gdb_debug
	rm -rf gdb_debug

clean:
	rm -rf main