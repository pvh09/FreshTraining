#include "gemtek_lib.h"

int main() {
    int integer_number = 0;
    get_input_integer(&integer_number);
    calculate_square_integer(integer_number);
    calculate_cube_integer(integer_number);
    print_square_cube_integer(integer_number);
    return 0;
}