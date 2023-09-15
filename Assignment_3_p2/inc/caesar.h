#ifndef _CAESAR_H_
#define _CAESAR_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_FILE_NAME 100

typedef enum
{
    EXIT_PROGRAM,
    ENCRYPT,
    DECRYPT,
    CHANGE_SHIFT,
    CHANGE_OUTPUT_FILE
} option_t;

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

/*!
 * @brief Change shift for program.
 *
 * @param[in] shift - int to save input from key board,
 *
 * @return The validated numerical value.
 */
int input_shift(int shift);

/**
 * @brief Gets the input file name from the user.
 *
 * @param file_name A character pointer to store the input file name.
 */
void input_file(char *file_name);

/**
 * @brief Encrypts the content of a file using the Caesar cipher algorithm.
 *
 * @param file_name The name of the input file.
 *
 * @param shift The shift value for encryption.
 *
 * @param flag The encryption flag (true for positive shift, false for negative shift).
 *
 * @param output_file_name The name of the output file to write the encrypted content.
 */
void encrypt(char *file_name, int shift, bool flag, char *output_file_name);

/**
 * @brief Decrypts the content of a file that was encrypted using the Caesar cipher algorithm.
 *
 * @param file_name The name of the input file.
 *
 * @param shift The shift value for decryption.
 *
 * @param flag The decryption flag (true for positive shift, false for negative shift).
 *
 * @param output_file_name The name of the output file to write the decrypted content.
 */
void decrypt(char *file_name, int shift, bool flag, char *output_file_name);

/**
 * @brief Changes the output file name.
 *
 * @param output_file_name A character pointer to store the new output file name.
 */
void change_output_file(char *output_file_name);

#endif