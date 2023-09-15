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

/**
 * @brief Main menu function.
 *
 * This function displays the main menu options and allows the user to choose from different modes.
 *
 * @param file_name The name of the input file.
 *
 * @param output_file_name The name of the output file.
 *
 * @param root The root of the tree node structure.
 */
void main_menu(char *file_name, char *output_file_name, tree_node_t *root);

/**
 * @brief Data input from the keyboard menu function.
 *
 * This function allows the user to input data from the keyboard and perform operations on the tree structure.
 *
 * @param output_file_name The name of the output file.
 *
 * @param root The root of the tree node structure.
 */
void data_from_keyboard_menu(char *output_file_name, tree_node_t *root);

/**
 * @brief Data input from file menu function.
 *
 * This function allows the user to input data from a file and perform operations on the tree structure.
 *
 * @param file_name The name of the input file.
 *
 * @param output_file_name The name of the output file.
 *
 * @param root The root of the tree node structure.
 */
void data_from_file_menu(char *file_name, char *output_file_name, tree_node_t *root);

#endif
