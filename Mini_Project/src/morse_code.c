#include "morse_code.h"

void build_morse_code_tree(tree_node_t* root) {
    // Define the Morse code mappings here
    insert(root, 'A', ".-");
    insert(root, 'B', "-...");
    insert(root, 'C', "-.-.");
    insert(root, 'D', "-..");
    insert(root, 'E', ".");
    insert(root, 'F', "..-.");
    insert(root, 'G', "--.");
    insert(root, 'H', "....");
    insert(root, 'I', "..");
    insert(root, 'J', ".---");
    insert(root, 'K', "-.-");
    insert(root, 'L', ".-..");
    insert(root, 'M', "--");
    insert(root, 'N', "-.");
    insert(root, 'O', "---");
    insert(root, 'P', ".--.");
    insert(root, 'Q', "--.-");
    insert(root, 'R', ".-.");
    insert(root, 'S', "...");
    insert(root, 'T', "-");
    insert(root, 'U', "..-");
    insert(root, 'V', "...-");
    insert(root, 'W', ".--");
    insert(root, 'X', "-..-");
    insert(root, 'Y', "-.--");
    insert(root, 'Z', "--..");
}

tree_node_t* create_node(char data) {
    tree_node_t* new_node = (tree_node_t*)malloc(sizeof(tree_node_t));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    new_node->data = data;
    new_node->p_left = NULL;
    new_node->p_right = NULL;
    return new_node;
}

void insert(tree_node_t* root, char character, char* code) {
    tree_node_t* current_node = root;

    for (int i = 0; code[i] != '\0'; i++) {
        if (code[i] == '.') {
            if (current_node->p_left == NULL) {
                current_node->p_left = (tree_node_t*)malloc(sizeof(tree_node_t));
                current_node->p_left->data = '\0'; // Initialize to null character
                current_node->p_left->p_left = NULL;
                current_node->p_left->p_right = NULL;
            }
            current_node = current_node->p_left;
        } else if (code[i] == '-') {
            if (current_node->p_right == NULL) {
                current_node->p_right = (tree_node_t*)malloc(sizeof(tree_node_t));
                current_node->p_right->data = '\0'; // Initialize to null character
                current_node->p_right->p_left = NULL;
                current_node->p_right->p_right = NULL;
            }
            current_node = current_node->p_right;
        }
    }
    current_node->data = character;
}

void printBinaryTree(tree_node_t* root, int space) {
    // Base case
    if (root == NULL) {
        return;
    }

    // Increase distance between levels
    space += 5;

    // Process right child first
    printBinaryTree(root->p_right, space);

    // Print current node with spacing
    printf("\n");
    for (int i = 5; i < space; i++) {
        printf(" ");
    }
    printf("%c\n", root->data);

    // Process left child
    printBinaryTree(root->p_left, space);
}
