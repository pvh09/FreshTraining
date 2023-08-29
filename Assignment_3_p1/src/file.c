#include "file.h"

void input_file(char* file_name) {
    do {
        printf("Enter the file name (up to 100 characters): ");
        if (fgets(file_name, MAX_FILE_NAME, stdin) == NULL) {
            return;
        }
        
        int len = strlen(file_name);
        if (len > 0 && file_name[len - 1] == '\n') {
            file_name[len - 1] = '\0';
        }
        
        if (strlen(file_name) > MAX_FILE_NAME) {
            printf("File name is too long. Please enter a name up to %d characters.\n", MAX_FILE_NAME);
        }
    } while (strlen(file_name) > MAX_FILE_NAME);
}

long get_file_size(char* file_name) {
    FILE* file = fopen(file_name, "rb");
    if (file == NULL) {
        return -1;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fclose(file);

    return size;
}

void output_size_file(char* file_name, long size) {
    if (size >= 0) {
        printf("The size of the %s file is %ld bytes!\n", file_name, size);
    } else {
        printf("Unable to open the file.\n");
    }
}
