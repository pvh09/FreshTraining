#include "gemtek_lib.h"

int main() {
    int integer_number = 0;
    get_input_integer(&integer_number);
    calculate_square_integer(integer_number);
    calculate_cube_integer(integer_number);
    print_square_cube_integer(integer_number);
    if (is_fibonacci(integer_number)) {
        printf("%d is a Fibonacci number.\n", integer_number);
    } else {
        printf("%d is not a Fibonacci number.\n", integer_number);
    }
    return 0;
}