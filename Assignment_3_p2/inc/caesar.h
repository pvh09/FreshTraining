#ifndef _CAESAR_H_
#define _CAESAR_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_FILE_NAME 15

typedef enum {
    EXIT_PROGRAM,
    ENCRYPT,
    DECRYPT,
    CHANGE_SHIFT,
    CHANGE_OUTPUT_FILE
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
double validate_num_input();

int input_shift(int shift);

void input_file(char* file_name);

void encrypt(char* file_name, int shift, bool flag);

void decrypt(char* file_name, int shift);

void change_new_output_file(char* file_name, int shift);

#endif