#include "morse_code.h"

// void menu(char *file_name, char *output_file_name, int shift)
// {
//     int choice;
//     system("clear");
//     do
//     {
//         printf("\n\n=========================");
//         printf("\n>> Input file:  %s", file_name);
//         printf("\n>> Output file opened: %s", output_file_name);
//         printf("\n>> %d (shift)", shift);
//         printf("\n  --------OPTION-------\n");
//         printf("      1. Encrypt a string\n");
//         printf("      2. Decrypt a string\n");
//         printf("      3. Change shift\n");
//         printf("      4. Change output file\n");
//         printf("      0. Exit\n");
//         printf("Enter your choice: ");
//         choice = validate_num_input();

//         switch (choice)
//         {
//         case ENCRYPT:
//             printf("\nEncrypted content: \n");
//             encrypt(file_name, shift, 1, output_file_name);
//             break;
//         case DECRYPT:
//             printf("\nDecrypted content: \n");
//             decrypt(file_name, shift, 0, output_file_name);
//             break;
//         case CHANGE_SHIFT:
//             printf("New shift - ");
//             shift = input_shift(shift);
//             menu(file_name, output_file_name, shift);
//             break;
//         case CHANGE_OUTPUT_FILE:
//             change_output_file(output_file_name);
//             menu(file_name, output_file_name, shift);
//             break;
//         case EXIT_PROGRAM:
//             printf(">> Exiting program.\n");
//             exit(1);
//         default:
//             printf("Invalid choice. Please enter a valid option.\n");
//         }
//     } while (choice != 4);
// }

int main()
{

    // char file_name[MAX_FILE_NAME];
    // char output_file_name[MAX_FILE_NAME];
    // input_file(file_name);
    // change_output_file(output_file_name);
    // int shift = input_shift(shift);
    // menu(file_name, output_file_name, shift);

    
    tree_node_t* root = create_node('A');
    root->p_left = create_node('B');
    root->p_right = create_node('C');
    root->p_left->p_left = create_node('D');
    root->p_left->p_right = create_node('E');
    root->p_right->p_left = create_node('F');
    root->p_right->p_right = create_node('G');

    printf("2D Representation of Binary Tree:\n\n");
    printBinaryTree(root, 0);

    return 0;
}