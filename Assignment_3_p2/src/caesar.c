#include "caesar.h"

// flag: 1 -- accept input is int, double
//       0 -- accept input is unsigned int
double validate_num_input(bool flag)
{
    char input_string[20] = {0};
    double input = -1;
    char* p_end;
    while (1)
    {
        __fpurge(stdin);
        scanf("%19s", input_string);
        if (flag == 1)
        {
            input = strtod(input_string, &p_end);
            if (*p_end == '\0')
            {
                return input;
            }
        }
        else if (flag == 0)
        {
            long long intPart = strtoll(input_string, &p_end, 10);
            if (p_end != input_string && *p_end == '\0' && intPart > 0)
            {
                input = intPart;
                return input;
            }
        }
        printf("\nWARNING: ");
        if (flag == 1)
        {
            printf("Only input is integer or double. Please enter again: ");
        }
        else if (flag == 0)
        {
            printf("Only input is integer bigger than 0. Please enter again: ");
        }
    }
    return input;
}

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


void encrypt(FILE* file, bool flag) {
    int ch;
    int shift = SHIFT;  // Initialize shift with default value

    if (!flag) {
        shift = 26 - SHIFT; // Modify shift for negative shift
    }

    while ((ch = fgetc(file)) != EOF) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            ch = (ch - base + shift) % 26 + base;
        }
        putchar(ch);
    }
}
// Function to decrypt the content of a file using Caesar cipher
void decrypt(FILE* file) {
    encrypt(file, 0); // Decrypting is the same as encrypting with negative shift
}