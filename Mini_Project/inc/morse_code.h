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
    EXIT_PROGRAM,
    ENCODING,
    DECODING,
}option_t;

// Structure for a node in the binary tree 
void build_morse_code_tree(tree_node_t* root);

// Function to create a new node for the binary tree
tree_node_t* create_node(char data);

// Function to insert a character into the binary tree
void insert(tree_node_t* root, char character, char* code);

// Function to encode a message to Morse code
void encode(tree_node_t* root, char* message, FILE* output_file);

// Function to decode Morse code to plain text
void decode(tree_node_t* root, char* morse_code, FILE* output_file);

// Function to build the Morse code binary tree from a mapping file
void build_morse_code_tree(tree_node_t* root);

void printBinaryTree(tree_node_t* root, int space);

#endif