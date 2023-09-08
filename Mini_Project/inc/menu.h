#ifndef _MENU_H
#define _MENU_H
#include "binary_tree.h"
#include "morse_code.h"
#include "file_handling.h"

typedef enum
{
    EXIT,
    ENCODING,
    DECODING,
    CHANGE_FILE
} option_t;

typedef enum
{
    EXIT_PROGRAM,
    KEYBOARD_DATA,
    READ_FILE,
} choice_t;


void main_menu(char *file_name, char *output_file_name, tree_node_t *root);

void data_from_keyboard_menu(char *output_file_name, tree_node_t *root);

void data_from_file_menu(char *file_name, char *output_file_name, tree_node_t *root);

#endif
