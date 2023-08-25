#ifndef _ARRAY_H_
#define _ARRAY_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>

#define N_MAX 50

void input_number_of_array(int *number_array);

void input_elements_array(int number_array, int *array);

int* init_array( int number_array);

void output_array(int* array, int number_array);

double calculate_avg_array(int *array, int number_array);

int calculate_elements_small_avg(int *array, int number_array, double average);

void move_even_odd(int *array, int number_array);

void free_array(int* array);
#endif