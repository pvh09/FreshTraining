#ifndef _CAESAR_H_
#define _CAESAR_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <ctype.h>
#include <stdbool.h>

#define SHIFT 3
#define MAX_FILE_NAME 100

typedef enum {
    TMP,
    ENCRYPT,
    DECRYPT,
    EXIT_PROGRAM
}option_t;

/*!
 * @brief Validate and input a numerical value.
 *
 * This function validates and inputs a numerical value from the user.
 *
 * @param[in] flag - Boolean flag to determine whether to validate for non-negative input.
 *
 * @return The validated numerical value.
 */
double validate_num_input(bool flag);

void input_file(char* file_name);

void encrypt(FILE* file, bool flag);

void decrypt(FILE* file);

#endif