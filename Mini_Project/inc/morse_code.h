#ifndef _MORSE_CODE_H_
#define _MORSE_CODE_H_
#include "binary_tree.h"

typedef enum
{
    EXIT,
    ENCODING,
    DECODING,
} option_t;

typedef enum
{
    EXIT_PROGRAM,
    KEYBOARD_DATA,
    READ_FILE,
} choice_t;

tree_node_t *build_morse_code_tree();

// Function to encode a message to Morse code
int encode_file(const char *input_filename, const char *output_filename, tree_node_t *root);

// Function to decode Morse code to plain text
void decode_file(const char *input_file, const char *output_file, tree_node_t *root);

void decode_keyboard(tree_node_t *root, const char *output_file);

int encode_keyboard(const char* output_filename, tree_node_t* root);

#endif