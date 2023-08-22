#include "array.h"

int main(){

    unsigned int N = 0;
    unsigned int *array;
    double avg_array = 0.00;
    input_number_of_array(&N);

    array = init_array(N);

    printf("Enter %d integers:\n", N);
    input_elements_array(N, array);

    printf("Array elements: ");
    output_array(array,N);

    avg_array = calculate_avg_array(array, N);
    printf("\nAverage value: %.2lf\n", avg_array);

    printf("Number of elements less than average: %d\n", calculate_elements_small_avg(array, N, avg_array));
    
    printf("Array elements after moving even and odd values: ");
    move_even_odd(array, N);
    output_array(array,N);
    printf("\n");

    free_array(array);
    return 0;
}