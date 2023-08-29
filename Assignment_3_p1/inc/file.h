#ifndef _FILE_H_
#define _FILE_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

#define MAX_FILE_NAME 100

void input_file(char* file_name);

long get_file_size(char* file_name);

void output_size_file(char* filename, long size);

#endif