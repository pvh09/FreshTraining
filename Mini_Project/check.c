#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Binary tree node structure
typedef struct tree_node {
    char data;
    struct tree_node* left;
    struct tree_node* right;
} tree_node_t;

char* map_morse_code(char character) {
    switch (character) {
        case 'A':
            return ".-";
        case 'B':
            return "-...";
        case 'C':
            return "-.-.";
        case 'D':
            return "-..";
        case 'E':
            return ".";
        case 'F':
            return "..-.";
        case 'G':
            return "--.";
        case 'H':
            return "....";
        case 'I':
            return "..";
        case 'J':
            return ".---";
        case 'K':
            return "-.-";
        case 'L':
            return ".-..";
        case 'M':
            return "--";
        case 'N':
            return "-.";
        case 'O':
            return "---";
        case 'P':
            return ".--.";
        case 'Q':
            return "--.-";
        case 'R':
            return ".-.";
        case 'S':
            return "...";
        case 'T':
            return "-";
        case 'U':
            return "..-";
        case 'V':
            return "...-";
        case 'W':
            return ".--";
        case 'X':
            return "-..-";
        case 'Y':
            return "-.--";
        case 'Z':
            return "--..";
        case ' ':
            return "/";
        default:
            return ""; // Return an empty string for characters not in the Morse code mapping
    }
}

void encode_character(char character, FILE* output) {
    char* morse_code = map_morse_code(character);
    printf("Digit: %d\n", character);
    fputs(morse_code, output);
}

// Function to encode Morse code for a given character
void encode_morse(tree_node_t* root, char c, FILE* output) {
    if (root == NULL)
        return;

    if (root->data == c) {
        // Perform the necessary action to output/record the Morse code
        // In this example, we write the Morse code to the output file
        encode_character(c, output);
    }

    encode_morse(root->left, c, output);
    encode_morse(root->right, c, output);
}

// Function to handle file I/O and encoding process
int encode_file(const char* input_filename, const char* output_filename, tree_node_t* root) {
    // Open the input file
    FILE* input = fopen(input_filename, "r");
    if (input == NULL) {
        perror("Error opening input file");
        return 1;
    }

    // Open the output file
    FILE* output = fopen(output_filename, "w");
    if (output == NULL) {
        perror("Error opening output file");
        fclose(input);
        return 1;
    }

    // Read input from the file character by character
    int c;
    while ((c = fgetc(input)) != EOF) {
        printf("input file: %c\n", c);
        if (c == ' ') {
            // Use the special character for space
            encode_morse(root, ' ', output);
        } else {
            encode_morse(root, (char)c, output);
        }

        // Add a space after each encoded character (except for the last one)
        if (!feof(input))
            fputs(" ", output);
    }

    // Close the input and output files
    fclose(input);
    fclose(output);

    return 0;
}

int main() {
    // Construct the binary tree representing the Morse code mappings
    tree_node_t* root = (tree_node_t*)malloc(sizeof(tree_node_t));
    root->data = 'A';
    root->left = (tree_node_t*)malloc(sizeof(tree_node_t));
    root->left->data = ' ';
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = (tree_node_t*)malloc(sizeof(tree_node_t));
    root->right->data = 'B';
    root->right->left = NULL;
    root->right->right = NULL;

    // Specify input and output filenames
    const char* input_filename = "input.txt";
    const char* output_filename = "output1.txt";

    // Encode the file
    int result = encode_file(input_filename, output_filename, root);
    if (result != 0) {
        printf("Error encoding file\n");
        return result;
    }

    return 0;
}