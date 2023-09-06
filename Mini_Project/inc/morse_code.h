#ifndef _MORSE_CODE_H_
#define _MORSE_CODE_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_FILE_NAME 100

// Structure for a node in the binary tree
typedef struct tree_node {
    char data;
    struct tree_node* p_left;
    struct tree_node* p_right;
} tree_node_t;


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

// Structure for a node in the binary tree 
tree_node_t* build_morse_code_tree();

// Function to create a new node for the binary tree
tree_node_t* create_node(char data);

// Function to insert a character into the binary tree
void insert(tree_node_t* root, char character, char* code);

// Function to encode a message to Morse code
void encode_file(const char* input_file, const char* output_file, tree_node_t* root);

// Function to decode Morse code to plain text
void decode_file(const char* input_file, const char* output_file, tree_node_t* root);

#endif