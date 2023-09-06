#include "morse_code.h"
#include "binary_tree.h"

void data_from_file_menu(char *file_name, char *output_file_name, tree_node_t* root)
{
    int choice;
    system("clear");
    do
    {
        printf(">> You choose enter data from FILE\n");
        printf("Your input file name: %s", file_name);
        printf("\n\n=========================");
        printf("\n  --------FILE DATA OPTION-------\n");
        printf("      1. Decode (convert morsecode to text)\n");
        printf("      2. Encode (convert text to morsecode)\n");
        printf("      0. Exit\n");
        printf("Enter your choice: ");
        choice = validate_num_input();

        switch (choice)
        {
        case DECODING:
            
            change_output_file(output_file_name);
            decode_file(file_name, output_file_name, root);
            break;
        case ENCODING:
            
            break;
        case EXIT:
            printf(">> Exiting program.\n");
            exit(1);
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 2);
}

void data_from_keyboard_menu(char *file_name, char *output_file_name, tree_node_t* root)
{
    int choice;
    system("clear");
    do
    {
        printf("\n\n=========================");
        printf("\n  --------DATA KEYBOARD OPTION-------\n");
        printf("      1. Decode (convert morsecode to text.\n");
        printf("      2. Encode (convert text to morsecode.\n");
        printf("      0. Exit\n");
        printf("Enter your choice: ");
        choice = validate_num_input();

        switch (choice)
        {
        case DECODING:
            printf(">> You choose enter data from keyboard");

            break;
        case ENCODING:
            printf(">> You choose enter data from FILE");
            
            break;
        case EXIT:
            printf(">> Exiting .\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 2);
}

void main_menu(char *file_name, char *output_file_name, tree_node_t* root)
{
    int choice;
    system("clear");
    do
    {
        printf("\n\n=========================");
        printf("\n  --------OPTION-------\n");
        printf("      1. Enter data from keyboard\n");
        printf("      2. Read data from file\n");
        printf("      0. Exit\n");
        printf("Enter your choice: ");
        choice = validate_num_input();

        switch (choice)
        {
        case KEYBOARD_DATA:
            printf(">> You choose enter data from keyboard\n");
            
            break;
        case READ_FILE:
            printf(">> You choose enter data from FILE\n");
            input_file(file_name);
            data_from_file_menu(file_name, output_file_name, root);
            break;
        case EXIT_PROGRAM:
            printf(">> Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 2);
}

int main(){

    char file_name[MAX_FILE_NAME];
    char output_file_name[MAX_FILE_NAME];
    tree_node_t* root = build_morse_code_tree();
    
    //main_menu(file_name, output_file_name, root);

    input_file(file_name);
    change_output_file(output_file_name);
    

    //encode_file(file_name, output_file_name, root);
    decode_file(file_name, output_file_name, root);

    // int result = encodeFromFile(file_name, output_file_name, root);

    // if (result == 0) {
    //     printf("Encoding completed successfully.\n");
    // } else {
    //     printf("Encoding encountered an error.\n");
    // }

    // return result;
    return 0;
}