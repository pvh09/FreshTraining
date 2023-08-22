#ifndef _ARRAY_H_
#define _ARRAY_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>

#define N_MAX 50

void input_number_of_array(unsigned int *number_array);

void input_elements_array(unsigned int number_array, unsigned int *array);

unsigned int* init_array( unsigned int number_array);

void output_array(unsigned int* array, unsigned int number_array);

double calculate_avg_array(unsigned int *array, unsigned int number_array);

unsigned int calculate_elements_small_avg(unsigned int *array, unsigned int number_array, double average);

void move_even_odd(unsigned int *array, unsigned int number_array);

void free_array(unsigned int* array);
#endif