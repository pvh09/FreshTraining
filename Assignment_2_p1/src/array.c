#include "array.h"

/*FUNCTION==========================================================
Function name: check_valid
Description: validate input data from keyboard
====================void free_matrix(matrix_t *matrix);===============================================*/
// flag: 1 -- accept input is int, double
//       0 -- accept input is int
static double check_valid(bool flag)
{
    char input_string[20] = {0};
    double input = -1;
    char *pEnd = {0};
    while (1)
    {
        scanf("%19s", input_string);
        if (flag == 1)
        {
            input = strtod(input_string, &pEnd);
            if (*pEnd == '\0')
            {
                return input;
            }
        }
        else if (flag == 0)
        {
            long long intPart = strtoll(input_string, &pEnd, 10);
            if (pEnd != input_string && *pEnd == '\0')
            {
                input = intPart;
                return input;
            }
        }
        printf("\nWARNING: ");
        if (flag == 1)
        {
            printf("Only input is integer or double. Please enter again: ");
        }
        else if (flag == 0)
        {
            printf("Only input is integer. Please enter again: ");
        }
    }
    return input;
}

void input_number_of_array(int *number_array)
{
    printf("Enter the number of elements (N <= %d): ", N_MAX);
    *number_array = check_valid(0);
    while (*number_array < 1 || *number_array > N_MAX)
    {
        printf("Invalid number of elements.\n");
        *number_array = check_valid(0);
    }
}

int *init_array(int number_array)
{
    int *array = (int *)malloc(N_MAX * sizeof(int));
    return array;
}

void input_elements_array(int number_array, int *array)
{
    int i;
    for (i = 0; i < number_array; i++)
    {
        array[i] = check_valid(0);
    }
}

void output_array(int *array, int number_array)
{
    int i;
    for (i = 0; i < number_array; i++)
    {
        printf("%d ", array[i]);
    }
}

double calculate_avg_array(int *array, int number_array)
{
    int sum = 0;
    int i;
    double average = 0;
    for (i = 0; i < number_array; i++)
    {
        sum += array[i];
    }
    average = (double)sum / number_array;
    return average;
}

int calculate_elements_small_avg(int *array, int number_array, double average)
{
    int count_less_than_average = 0;
    int i;
    for (i = 0; i < number_array; i++)
    {
        if (array[i] < average)
        {
            count_less_than_average++;
        }
    }
    return count_less_than_average;
}

static void swap_element(int *num1, int *num2)
{
    int temp = 0;
    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void move_even_odd(int *array, int number_array)
{
    int left = 0;
    int right = number_array - 1;

    while (left < right)
    {
        while (array[left] % 2 == 1 && left < right)
        {
            left++;
        }

        while (array[right] % 2 == 0 && left < right)
        {
            right--;
        }
        if (left < right)
        {
            swap_element(&array[left], &array[right]);
            left++;
            right--;
        }
    }
}

void free_array(int *array)
{
    if (array != NULL)
    {
        free(array);
    }
    array = NULL;
}