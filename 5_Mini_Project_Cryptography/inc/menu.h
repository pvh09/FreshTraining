#ifndef _MENU_H_
#define _MENU_H_
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
void main_menu(char *file_name, char *output_file_name);

#endif
