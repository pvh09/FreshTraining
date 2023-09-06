#ifndef _MORSE_CODE_H_
#define _MORSE_CODE_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <ctype.h>
#include <stdbool.h>
#include "binary_tree.h"
#define MAX_FILE_NAME 100

typedef enum {
    EXIT,
    DECODING,
    ENCODING
}option_t;

typedef enum {
    EXIT_PROGRAM,
    KEYBOARD_DATA,
    READ_FILE,
}choice_t;

double validate_num_input();

void input_file(char *file_name);

void change_output_file(char* output_file_name);

tree_node_t* build_morse_code_tree();

// Function to encode a message to Morse code
void encode_file(const char* input_file, const char* output_file, tree_node_t* root);

// Function to decode Morse code to plain text
void decode_file(const char* input_file, const char* output_file, tree_node_t* root);

int encodeFromFile(const char* inputFileName, const char* outputFileName, tree_node_t* root);

#endif