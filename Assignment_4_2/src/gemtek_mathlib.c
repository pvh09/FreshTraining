#include "gemtek_lib.h"

int validate_num_input()
{
    char input_string[20] = {0};
    long input = -1;
    char *p_end = {0};

    while (1)
    {
        __fpurge(stdin);
        scanf("%19s", input_string);

        // Convert the input string to a long integer
        input = strtol(input_string, &p_end, 10);

        // Check for conversion errors
        if (p_end != input_string && *p_end == '\0')
        {
            // Check if the input is within the range of INT_MIN and INT_MAX
            if (input >= INT_MIN && input <= INT_MAX)
            {
                return (int)input; // Convert and return as an int
            }
            else
            {
                printf("\nWARNING: Input out of range. Please enter again: ");
            }
        }
        else
        {
            printf("\nWARNING: Only input integer is allowed. Please enter again: ");
        }
    }
}

void get_input_integer(int *integer_number)
{
    printf("Enter a integer number: ");
    *integer_number = validate_num_input();
}

double calculate_square_integer(int integer_number)
{
    double square = 0.0f;
    //square = pow(integer_number, 2);
    square = (long long)integer_number * integer_number;
    return square;
}

double calculate_cube_integer(int integer_number)
{
    double cube = 0.0f;
    cube = (double)integer_number * integer_number * integer_number;
    return cube;
}

void print_square_cube_integer(int integer_number)
{
    printf("Square is %0.2f\n", calculate_square_integer(integer_number));
    printf("Cube is %0.2f\n", calculate_cube_integer(integer_number));
}

int is_perfect_square(double x)
{
    double s = round(sqrt(x));
    return s * s == x;
}

int is_fibonacci(int integer_number)
{
    return is_perfect_square((double)5 * integer_number * integer_number + 4) || is_perfect_square(5 * integer_number * integer_number - 4);
}
