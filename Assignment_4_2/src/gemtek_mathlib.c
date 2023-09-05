#include "gemtek_lib.h"

static double validate_num_input()
{
    char input_string[20] = {0};
    double input = -1;
    char *p_end;
    while (1)
    {
        scanf("%19s", input_string);
            long long intPart = strtoll(input_string, &p_end, 10);
            if (p_end != input_string && *p_end == '\0')
            {
                input = intPart;
                return input;
            }
        printf("\nWARNING: ");
        printf(">> Only input is integer. Please enter again: ");
    }
    return input;
}

void get_input_integer(int* integer_number ){
    printf("Enter a integer number: ");
    *integer_number = validate_num_input();
}

int calculate_square_integer(int integer_number ){
    int square = 0;
    square =  integer_number * integer_number;
    return square;
}

int calculate_cube_integer(int integer_number ){
    int cube = 0;
    cube = integer_number * integer_number * integer_number;
    return cube;
}

void print_square_cube_integer(int integer_number ){
    printf("Square of %d is %d\n",integer_number, calculate_square_integer(integer_number));
    printf("Cube of %d is %d\n",integer_number, calculate_cube_integer(integer_number));
}

int is_perfect_square(int x) {
    int s = sqrt(x);
    return s * s == x;
}

int is_fibonacci(int integer_number) {
    return is_perfect_square(5 * integer_number * integer_number + 4) || is_perfect_square(5 * integer_number * integer_number - 4);
}
