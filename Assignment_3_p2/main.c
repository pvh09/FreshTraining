#include "caesar.h"

void menu(char* file_name){
    int choice, shift;
    
    shift = input_shift(shift);
    system("clear");
    do {
        printf("\n\n=========================");
        printf("\n>> %s (open)", file_name);  
        printf("\n>> %d (shift)", shift); 
        printf("\n  --------OPTION-------\n");
        printf("      1. Encrypt a string\n");
        printf("      2. Decrypt a string\n");
        printf("      3. Change shift\n");
        printf("      4. Change output file\n");
        printf("      0. Exit\n");
        printf("Enter your choice: ");
        choice = validate_num_input();

        switch (choice) {
            case ENCRYPT:
                printf("\nEncrypted content: \n");
                encrypt(file_name, shift, 1);
                break;
            case DECRYPT:
                printf("\nDecrypted content: \n");
                decrypt(file_name, shift);
                break;
            case CHANGE_SHIFT:
                printf("New shift - ");
                menu(file_name);
                break;
            case CHANGE_OUTPUT_FILE:
                change_new_output_file(file_name, shift);
                break;
            case EXIT_PROGRAM:
                printf(">> Exiting program.\n");
                exit(1);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);
}

int main(){

    char file_name[MAX_FILE_NAME];
    char output_file_name[MAX_FILE_NAME];
    input_file(file_name);
    menu(file_name);
    
    return 0;
}