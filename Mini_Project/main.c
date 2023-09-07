#include "morse_code.h"
#include "binary_tree.h"
#include "file_handling.h"

void data_from_file_menu(char *file_name, char *output_file_name, tree_node_t *root)
{
    int choice;
    change_output_file(output_file_name);
    system("clear");
    do
    {
        printf("\n***************************************\n");
        printf(">> You choose enter data from FILE\n");
        printf(">> Your input file name: %s\n", file_name);
        printf(">> Your output file name: %s", output_file_name);
        printf("\n=======================================");
        printf("\n----------------OPTION-----------------\n");
        printf("  1. Encode (convert text to morsecode)\n");
        printf("  2. Decode (convert morsecode to text)\n");
        printf("  0. Exit\n");
        printf("\nEnter your choice: ");
        choice = validate_num_input();

        switch (choice)
        {
        case ENCODING:
            int result = encode_file(file_name, output_file_name, root);
            printf("Message: ");
            read_and_print_file(output_file_name);
            if (result != 0)
            {
                printf("\n\n>> Error encoding file\n");
            }
            else
            {
                printf("\n\n>> File encoded successfully. Please check folder\n");
            }
            break;
        case DECODING:
            decode_file(file_name, output_file_name, root);
            printf("Message: ");
            read_and_print_file(output_file_name);
            printf("\n");
            break;
        case EXIT:
            printf(">> Exit. Back to main program\n");
            break;
        default:
            printf(">> Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);
}

void data_from_keyboard_menu(char *output_file_name, tree_node_t *root)
{
    int choice;
    change_output_file(output_file_name);
    system("clear");
    do
    {
        printf("\n***************************************\n");
        printf(">> You choose enter data: KEYBOARD\n");
        printf(">> Your output file name: %s", output_file_name);
        printf("\n=======================================");
        printf("\n----------------OPTION-----------------\n");
        printf("  1. Encode (convert text to morsecode)\n");
        printf("  2. Decode (convert morsecode to text)\n");
        printf("  0. Exit\n");
        printf("\nEnter your choice: ");
        choice = validate_num_input();

        switch (choice)
        {
        case ENCODING:
            int result = encode_keyboard(output_file_name, root);
            printf("Message: ");
            read_and_print_file(output_file_name);
            if (result != 0)
            {
                printf("\n\n>> Error encoding file\n");
            }
            else
            {
                printf("\n\n>> File encoded successfully. Please check folder\n");
            }
            break;
        case DECODING:
            decode_keyboard(root, output_file_name);
            printf("Message: ");
            read_and_print_file(output_file_name);
            printf("\n");
            break;
        case EXIT:
            printf(">> Exit. Back to main program\n");
            break;
        default:
            printf(">> Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);
}

void main_menu(char *file_name, char *output_file_name, tree_node_t *root)
{
    int choice;
    //system("clear");
    do
    {
        printf("\n=======================================");
        printf("\n----------------OPTION-----------------\n");
        printf("      1. Enter data from keyboard\n");
        printf("      2. Read data from file\n");
        printf("      0. Exit\n");
        printf("\nEnter your choice: ");

        choice = validate_num_input();

        switch (choice)
        {
        case KEYBOARD_DATA:
            printf(">> You choose enter data from keyboard\n");
            data_from_keyboard_menu(output_file_name, root);
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
            printf(">> Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);
}

int main()
{

    char file_name[MAX_FILE];
    char output_file_name[MAX_FILE];
    tree_node_t *root = build_morse_code_tree();

    main_menu(file_name, output_file_name, root);

    // input_file(file_name);
    //change_output_file(output_file_name);

    // encode_file(file_name, output_file_name, root);
    // decode_file(file_name, output_file_name, root);

    // Encode the file
    // int result = encode_file(file_name, output_file_name, root);
    // if (result != 0)
    // {
    //     printf("Error encoding file\n");
    //     return result;
    // }

    // decode_keyboard(root, output_file_name);
    
    // int result = encode_keyboard(output_file_name, root);
    // if (result != 0)
    // {
    //     printf("Error encoding file\n");
    //     return result;
    // }
    // else
    // {
    //     printf("File encoded successfully. Please check folder\n");
    // }
    
    return 0;
}