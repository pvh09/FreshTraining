#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_FILE 100

// Structure for a node in the binary tree
typedef struct tree_node
{
    char data = {0};
    struct tree_node *p_left;
    struct tree_node *p_right;
} tree_node_t;

/**
 * @brief Create a new node for the binary tree.
 *
 * This function creates a new node for the binary tree with the specified data.
 *
 * @param data The data value to be stored in the new node.
 * 
 * @return A pointer to the newly created node.
 */
tree_node_t *create_node(char data);

/**
 * @brief Insert a character into the binary tree.
 *
 * This function inserts a character along with its corresponding code into the binary tree.
 *
 * @param root The root of the binary tree.
 * 
 * @param character The character to be inserted.
 * 
 * @param code The code associated with the character.
 */
void insert(tree_node_t *root, char character, char *code);


#endif
