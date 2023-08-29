#include "caesar.h"

void menu(char* file_name){
    int choice;

    FILE* file = fopen(file_name, "rb");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        return ;
    }

    do {
        printf("\n----------OPTION-----------\n");
        printf("    1. Encrypt a string\n");
        printf("    2. Decrypt a string\n");
        printf("    0. Exit\n");
        printf("Enter your choice: ");
        choice = validate_num_input(0);

        switch (choice) {
            case ENCRYPT:
                printf("Encrypted content: ");
                encrypt(file, 1);
                break;
            case DECRYPT:
                printf("Decrypted content: ");
                decrypt(file);
                break;
            case EXIT_PROGRAM:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);
}

int main(){

    int choice;
    char file_name[MAX_FILE_NAME];
    input_file(file_name);
    menu(file_name);
    
    return 0;
}