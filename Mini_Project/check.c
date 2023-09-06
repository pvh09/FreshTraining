// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <stdio_ext.h>
// #include <ctype.h>
// #include <stdbool.h>

// // Define a structure for the Morse Tree node
// typedef struct TreeNode {
//     char data;
//     struct TreeNode* dot;  // Dot child
//     struct TreeNode* dash; // Dash child
// } TreeNode;

// // Function to create a new Morse code tree node
// TreeNode* createMorseTreeNode(char data) {
//     TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
//     newNode->data = data;
//     newNode->dot = NULL;
//     newNode->dash = NULL;
//     return newNode;
// }

// // Function to build a Morse code binary tree
// TreeNode* createMorseCodeTree() {
//     TreeNode* root = createMorseTreeNode(' ');

//     // Define Morse code mappings and build the tree
//     const char* morseMappings[] = {
//         ".-",   // A
//         "-...", // B
//         "-.-.", // C
//         "-..",  // D
//         ".",    // E
//         "..-.", // F
//         "--.",  // G
//         "....", // H
//         "..",   // I
//         ".---", // J
//         "-.-",  // K
//         ".-..", // L
//         "--",   // M
//         "-.",   // N
//         "---",  // O
//         ".--.", // P
//         "--.-", // Q
//         ".-.",  // R
//         "...",  // S
//         "-",    // T
//         "..-",  // U
//         "...-", // V
//         ".--",  // W
//         "-..-", // X
//         "-.--", // Y
//         "--.."  // Z
//     };

//     for (int i = 0; i < 26; i++) {
//         TreeNode* current = root;
//         const char* mapping = morseMappings[i];

//         for (int j = 0; mapping[j] != '\0'; j++) {
//             if (mapping[j] == '.') {
//                 if (current->dot == NULL) {
//                     current->dot = createMorseTreeNode('\0');
//                 }
//                 current = current->dot;
//             } else if (mapping[j] == '-') {
//                 if (current->dash == NULL) {
//                     current->dash = createMorseTreeNode('\0');
//                 }
//                 current = current->dash;
//             }
//         }
//         current->data = 'A' + i; // Assign the character to the leaf node
//     }

//     return root;
// }

// void encode(TreeNode* root, char character, FILE* output) {
//     if (root == NULL || character == ' ') {
//         return; // Invalid character or space, do nothing
//     }

//     if (isalpha(character)) {
//         character = toupper(character); // Convert character to uppercase
//         TreeNode* current = root;
//         while (current != NULL && current->data != character) {
//             if (character < current->data) {
//                 fprintf(output, "."); // Dot for left traversal
//                 current = current->dot;
//             } else {
//                 fprintf(output, "-"); // Dash for right traversal
//                 current = current->dash;
//             }
//         }

//         if (current != NULL) {
//             fprintf(output, " "); // Space to separate Morse code characters
//         }
//     }
// }

// // Function to encode text to Morse code using a binary tree
// void encodeText(TreeNode* root, const char* text, FILE* output) {
//     if (root == NULL || text == NULL) {
//         return; // Invalid parameters
//     }

//     for (int i = 0; text[i] != '\0'; i++) {
//         encode(root, text[i], output);
//     }
// }

// // Function to free the memory of the Morse code tree
// void freeMorseCodeTree(TreeNode* root) {
//     if (root == NULL) {
//         return;
//     }

//     freeMorseCodeTree(root->dot);
//     freeMorseCodeTree(root->dash);
//     free(root);
// }

// // Function to open input and output files and perform encoding
// int encodeFromFile(const char* inputFileName, const char* outputFileName) {
//     // Build your Morse code tree (you can use your existing code for this)
//     TreeNode* root = createMorseCodeTree(); // Make sure you have this function implemented

//     // Open the input file for reading
//     FILE* input = fopen(inputFileName, "r");
//     if (input == NULL) {
//         printf("Unable to open input file: %s\n", inputFileName);
//         freeMorseCodeTree(root);
//         return 1; // Exit with an error code
//     }

//     // Open the output file for writing
//     FILE* output = fopen(outputFileName, "w");
//     if (output == NULL) {
//         printf("Unable to open output file: %s\n", outputFileName);
//         fclose(input);
//         freeMorseCodeTree(root);
//         return 1; // Exit with an error code
//     }

//     char text[1000];
//     while (fgets(text, sizeof(text), input) != NULL) {
//         // Remove the newline character from the input
//         text[strcspn(text, "\n")] = '\0';

//         // Encode the text to Morse code and write to the output file
//         encodeText(root, text, output);

//         // Add a newline character after each line
//         fprintf(output, "\n");
//     }

//     // Close the input and output files
//     fclose(input);
//     fclose(output);

//     // Free the Morse code tree
//     freeMorseCodeTree(root);

//     return 0;
// }

// int main() {
//     const char* inputFileName = "check.txt";
//     const char* outputFileName = "1.txt";

//     int result = encodeFromFile(inputFileName, outputFileName);

//     if (result == 0) {
//         printf("Encoding completed successfully.\n");
//     } else {
//         printf("Encoding encountered an error.\n");
//     }

//     return result;
// }


// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <stdio_ext.h>
// #include <ctype.h>
// #include <stdbool.h>


// // Define a structure for the Morse Tree node
// typedef struct TreeNode {
//     char data;
//     struct TreeNode* dot;  // Dot child
//     struct TreeNode* dash; // Dash child
// } TreeNode;

// // Function to create a new Morse code tree node
// TreeNode* createMorseTreeNode(char data) {
//     TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
//     newNode->data = data;
//     newNode->dot = NULL;
//     newNode->dash = NULL;
//     return newNode;
// }

// // Function to build a Morse code binary tree
// TreeNode* createMorseCodeTree() {
//     TreeNode* root = createMorseTreeNode(' ');

//     // Define Morse code mappings and build the tree
//     const char* morseMappings[] = {
//         ".-",   // A
//         "-...", // B
//         "-.-.", // C
//         "-..",  // D
//         ".",    // E
//         "..-.", // F
//         "--.",  // G
//         "....", // H
//         "..",   // I
//         ".---", // J
//         "-.-",  // K
//         ".-..", // L
//         "--",   // M
//         "-.",   // N
//         "---",  // O
//         ".--.", // P
//         "--.-", // Q
//         ".-.",  // R
//         "...",  // S
//         "-",    // T
//         "..-",  // U
//         "...-", // V
//         ".--",  // W
//         "-..-", // X
//         "-.--", // Y
//         "--.."  // Z
//     };

//     for (int i = 0; i < 26; i++) {
//         TreeNode* current = root;
//         const char* mapping = morseMappings[i];

//         for (int j = 0; mapping[j] != '\0'; j++) {
//             if (mapping[j] == '.') {
//                 if (current->dot == NULL) {
//                     current->dot = createMorseTreeNode('\0');
//                 }
//                 current = current->dot;
//             } else if (mapping[j] == '-') {
//                 if (current->dash == NULL) {
//                     current->dash = createMorseTreeNode('\0');
//                 }
//                 current = current->dash;
//             }
//         }
//         current->data = 'A' + i; // Assign the character to the leaf node
//     }

//     return root;
// }

// void get_path_to_node(TreeNode *g_root, TreeNode *node, char *buffer)
// {
//     // Base case: If the g_root is NULL or the node is not found
//     if (g_root == NULL || node == NULL) {
//         return;
//     }

//     // Create a pointer to g_root
//     int index = 0;
//     TreeNode *curr_node = g_root;

//     while (curr_node != node) {
//         // Check if node is on the left
//         if (curr_node->left != NULL && get_node_by_data(curr_node->left, node->data) != NULL) {
//             buffer[index] = '.';
//             curr_node = curr_node->left;
//         }
//         // Check if node is on the right
//         else if (curr_node->right != NULL && get_node_by_data(curr_node->right, node->data) != NULL) {
//             buffer[index] = '-';
//             curr_node = curr_node->right;
//         }
//         else {
//             // Clear the buffer to avoid appending invalid characters
//             memset(buffer, 0, MAX_STRING_SIZE);
//             return;
//         }

//         index++;
//     }

//     return;
// }

// void encode_morse(char *text, char *decode_text)
// {
//     TreeNode *node_temp;
//     char s_temp[255];

//     // Clear decode_text
//     memset(decode_text, 0, sizeof(decode_text));

//     for (int i = 0; i < strlen(text); i++) {
//         if (text[i] == ' ') {
//             strcat(decode_text, "/ ");
//             continue;
//         }

//         // Clear s_temp before using it
//         memset(s_temp, 0, sizeof(s_temp));

//         node_temp = get_node_by_data(g_root, text[i]);
//         if (node_temp != NULL) {
//             get_path_to_node(g_root, node_temp, s_temp);
//             strcat(decode_text, s_temp);
//             strcat(decode_text, " ");
//         }
//     }
// }

// tree_node_t *get_node_by_data(tree_node_t *g_root, char data)
// {
//     // Base case: If the g_root is NULL or the data matches, return the g_root
//     if (g_root == NULL || g_root->data == data) {
//         return g_root;
//     }

//     // Recursively search in the left and right subtrees
//     tree_node_t *left_node = get_node_by_data(g_root->left, data);
//     if (left_node != NULL) {
//         return left_node;
//     }

//     tree_node_t *right_node = get_node_by_data(g_root->right, data);
//     if (right_node != NULL) {
//         return right_node;
//     }

//     // Node not found
//     return NULL;
// }

// // Function to free the memory of the Morse code tree
// void freeMorseCodeTree(TreeNode* root) {
//     if (root == NULL) {
//         return;
//     }

//     freeMorseCodeTree(root->dot);
//     freeMorseCodeTree(root->dash);
//     free(root);
// }

// // Function to open input and output files and perform encoding
// int encodeFromFile(const char* inputFileName, const char* outputFileName) {
//     // Build your Morse code tree (you can use your existing code for this)
//     TreeNode* root = createMorseCodeTree(); // Make sure you have this function implemented

//     // Open the input file for reading
//     FILE* input = fopen(inputFileName, "r");
//     if (input == NULL) {
//         printf("Unable to open input file: %s\n", inputFileName);
//         freeMorseCodeTree(root);
//         return 1; // Exit with an error code
//     }

//     // Open the output file for writing
//     FILE* output = fopen(outputFileName, "w");
//     if (output == NULL) {
//         printf("Unable to open output file: %s\n", outputFileName);
//         fclose(input);
//         freeMorseCodeTree(root);
//         return 1; // Exit with an error code
//     }

//     char text[1000];
//     while (fgets(text, sizeof(text), input) != NULL) {
//         // Remove the newline character from the input
//         text[strcspn(text, "\n")] = '\0';

//         // Encode the text to Morse code and write to the output file
//         encodeText(root, text, output);

//         // Add a newline character after each line
//         fprintf(output, "\n");
//     }

//     // Close the input and output files
//     fclose(input);
//     fclose(output);

//     // Free the Morse code tree
//     freeMorseCodeTree(root);

//     return 0;
// }

// int main() {
//     const char* inputFileName = "check.txt";
//     const char* outputFileName = "1.txt";

//     int result = encodeFromFile(inputFileName, outputFileName);

//     if (result == 0) {
//         printf("Encoding completed successfully.\n");
//     } else {
//         printf("Encoding encountered an error.\n");
//     }

//     return result;
// }



