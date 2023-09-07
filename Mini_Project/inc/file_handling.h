#ifndef _FILE_HANDLING_H_
#define _FILE_HANDLING_H_
#include "binary_tree.h"

double validate_num_input();

bool check_digit(char* file_name);

//check file input is existed in folder
bool is_exist_input_file(char* file_name);

//check file output is existed in folder
bool is_exist_out_file(char* file_name);

//check file exist in folder
bool check_file_exist(char* file_name, bool check_in_out);

bool is_invalid_file_name(const char *file_name);

//check length of output name and check name of ouput have no " \/:*?\"<>| "
bool is_over_range(char* file_name);

//enter name of file
void get_file_name(char* file_name, bool flag_check_input_output);

void input_file(char *file_name);

void output_file(char* output_file_name);

void change_output_file(char* output_file_name);

void read_and_print_file(const char* filename) ;

#endif