#include "array.h"

int main(){

    int number_of_element = 0;
    int *array;
    double avg_array = 0.00;
    input_number_of_array(&number_of_element);

    array = init_array(number_of_element);

    printf("Enter %d integers:\n", number_of_element);
    input_elements_array(number_of_element, array);

    printf("Array elements: ");
    output_array(array,number_of_element);

    avg_array = calculate_avg_array(array, number_of_element);
    printf("\nAverage value: %.2lf\n", avg_array);

    printf("number_of_elementumber of elements less than average: %d\n", calculate_elements_small_avg(array, number_of_element, avg_array));
    
    printf("Array elements after moving even and odd values: ");
    move_even_odd(array, number_of_element);
    output_array(array,number_of_element);
    printf("\n");

    free_array(array);
    return 0;
}