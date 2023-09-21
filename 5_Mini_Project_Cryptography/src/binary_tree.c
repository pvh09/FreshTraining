#include "binary_tree.h"

tree_node_t *create_node(char data)
{
    tree_node_t *new_node = (tree_node_t *)malloc(sizeof(tree_node_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    new_node->data = data;
    new_node->p_left = NULL;
    new_node->p_right = NULL;
    return new_node;
}

void insert(tree_node_t *root, char character, char *code)
{
    tree_node_t *current_node = root;

    for (int i = 0; code[i] != '\0'; i++)
    {
        if (code[i] == '.')
        {
            if (current_node->p_left == NULL)
            {
                current_node->p_left = (tree_node_t *)malloc(sizeof(tree_node_t));
                current_node->p_left->data = '\0'; // Initialize to null character
                current_node->p_left->p_left = NULL;
                current_node->p_left->p_right = NULL;
            }
            current_node = current_node->p_left;
        }
        else if (code[i] == '-')
        {
            if (current_node->p_right == NULL)
            {
                current_node->p_right = (tree_node_t *)malloc(sizeof(tree_node_t));
                current_node->p_right->data = '\0'; // Initialize to null character
                current_node->p_right->p_left = NULL;
                current_node->p_right->p_right = NULL;
            }
            current_node = current_node->p_right;
        }
    }
    current_node->data = character;
}
