/**
 * @brief Validate numerical input.
 *
 * This function validates numerical input entered by the user.
 *
 * @return The validated numerical input as a double.
 */
double validate_num_input();

/**
 * @brief Check if a string consists of digits.
 *
 * This function checks if a given string consists of digits.
 *
 * @param file_name The string to be checked.
 * 
 * @return True if the string consists of digits; otherwise, false.
 */
bool check_digit(char* file_name);

/**
 * @brief Check if a file input exists in the folder.
 *
 * This function checks if a file input exists in the folder.
 *
 * @param file_name The name of the input file to be checked.
 * 
 * @return True if the file exists; otherwise, false.
 */
bool is_exist_input_file(char* file_name);

/**
 * @brief Check if a file output exists in the folder.
 *
 * This function checks if a file output exists in the folder.
 *
 * @param file_name The name of the output file to be checked.
 * 
 * @return True if the file exists; otherwise, false.
 */
bool is_exist_out_file(char* file_name);

/**
 * @brief Check if a file exists in the folder.
 *
 * This function checks if a file exists in the folder based on the specified file name.
 *
 * @param file_name The name of the file to be checked.
 * 
 * @param check_in_out A flag to indicate whether to check for input or output files (true for input, false for output).
 * 
 * @return True if the file exists; otherwise, false.
 */
bool check_file_exist(char* file_name, bool check_in_out);

/**
 * @brief Check if a file name is invalid.
 *
 * This function checks if a file name contains invalid characters.
 *
 * @param file_name The file name to be checked.
 * 
 * @return True if the file name is invalid; otherwise, false.
 */
bool is_invalid_file_name(const char *file_name);

/**
 * @brief Check if a file name exceeds a specified length or contains invalid characters.
 *
 * This function checks if a file name exceeds a specified length or contains invalid characters such as " \/:*?\"<>|".
 *
 * @param file_name The file name to be checked.
 * 
 * @return True if the file name exceeds the length or contains invalid characters; otherwise, false.
 */
bool is_over_range(char* file_name);

/**
 * @brief Get the name of a file.
 *
 * This function allows the user to enter the name of a file.
 *
 * @param file_name The variable to store the entered file name.
 * 
 * @param flag_check_input_output A flag to indicate whether the file name is for input or output.
 */
void get_file_name(char* file_name, bool flag_check_input_output);

/**
 * @brief Input data from a file.
 *
 * This function reads data from a file specified by the file name.
 *
 * @param file_name The name of the input file.
 */
void input_file(char *file_name);

/**
 * @brief Output data to a file.
 *
 * This function outputs data to a file specified by the output file name.
 *
 * @param output_file_name The name of the output file.
 */
void output_file(char* output_file_name);

/**
 * @brief Change the file for data output.
 *
 * This function allows the user to change the output file name.
 *
 * @param output_file_name The variable to store the new output file name.
 */
void change_file(char* output_file_name);

/**
 * @brief Read and print data from a file.
 *
 * This function reads data from a file and prints it to the console.
 *
 * @param filename The name of the file to be read.
 */
void read_and_print_file(const char* filename);
