#ifndef _MENU_H
#define _MENU_H
#include "binary_tree.h"
#include "morse_code.h"
#include "file_handling.h"

void main_menu(char *file_name, char *output_file_name, tree_node_t *root);

void data_from_keyboard_menu(char *output_file_name, tree_node_t *root);

void data_from_file_menu(char *file_name, char *output_file_name, tree_node_t *root);

#endif
