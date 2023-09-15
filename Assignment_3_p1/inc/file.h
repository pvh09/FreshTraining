#ifndef _FILE_H_
#define _FILE_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

#define MAX_FILE_NAME 100

/**
 * @brief Input a file name from the user.
 *
 * This function prompts the user to input a file name and validates the input.
 *
 * @param[in,out] file_name - Pointer to a character array to store the input file name.
 *
 * @return None.
 */
void input_file(char *file_name);

/**
 * @brief Get the size of a given file.
 *
 * This function calculates and returns the size of the specified file.
 *
 * @param[in] file_name - Pointer to a character array containing the name of the file.
 *
 * @return The size of the file, or -1 if an error occurred.
 */
long get_file_size(char *file_name);

/**
 * @brief Output the size of a file to the console.
 *
 * This function displays the size of a file along with its name.
 *
 * @param[in] filename - Pointer to a character array containing the name of the file.
 *
 * @param[in] size - The size of the file.
 *
 * @return None.
 */
void output_size_file(char *filename, long size);
#endif