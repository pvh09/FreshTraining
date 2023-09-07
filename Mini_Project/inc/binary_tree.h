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
    char data;
    struct tree_node *p_left;
    struct tree_node *p_right;
} tree_node_t;

// Function to create a new node for the binary tree
tree_node_t *create_node(char data);

// Function to insert a character into the binary tree
void insert(tree_node_t *root, char character, char *code);

#endif
