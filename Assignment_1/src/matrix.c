#include "matrix.h"

/*FUNCTION==========================================================
Function name: free_matrix
Description: release memory
===================================================================*/
void free_matrix(matrix_t *matrix) {
    if(matrix != NULL) {
        for(int i = 0; i < matrix->row; i++) {
            free(matrix->array[i]);
        }
        free(matrix->array);
        free(matrix);
    }
    matrix = NULL; 
}
/*FUNCTION==========================================================
Function name: check_row_col_matrix
Description: check valid condition for row and column
===================================================================*/
static bool check_row_col_matrix(int row_matrix_a, int col_matrix_a, int row_matrix_b, int col_matrix_b, bool flag) {
    if(flag == 1) {
        if(row_matrix_a != row_matrix_b || col_matrix_a != col_matrix_b) {
            return true;
        }
    }
    else {
        if(col_matrix_a != row_matrix_b) {
            return true;
        }
    }
    return false;
}

/*FUNCTION==========================================================
Function name: check_valid
Description: validate input data from keyboard
====================void free_matrix(matrix_t *matrix);===============================================*/

// static double check_valid(bool flag) {
//     char input_string[20] = {0};
//     double input = -1;
//     char *pEnd;
//     while (1) {
//         scanf("%19s", input_string);
//         if (flag == 1) {
//             input = strtod(input_string, &pEnd);
//             if (*pEnd == '\0') {
//                 return input;
//             }
//         } else if (flag == 0) {
//             long long intPart = strtoll(input_string, &pEnd, 10);
//             if (pEnd != input_string && *pEnd == '\0' && intPart > 0 && intPart <= UINT_MAX) {
//                 input = intPart;
//                 return input;
//             }
//         }
//         printf("Invalid input!! Please enter again: \n");
//     }
//     return input;
// }

static int clean_stdin()
{
    while(getchar() != '\n');
    return 1;
}

static float get_input_float() 
{
    float return_value = 0;

    while (scanf("%f", &return_value) != 1)
    {
        printf("Please enter a number: ");
        while(getchar() != '\n');
    }
    
    return return_value;
}

static int get_input_int() 
{
    int input;
    unsigned int i =0;
    char c;

    while ((scanf("%d", &input) != 1 || input < 1) && clean_stdin())
    {
        printf("Input valid!! Enter again:  ");
    }
    return input;
}

/*FUNCTION==========================================================
===================================================================*/
matrix_t* init_matrix(int row, int col) {
    matrix_t* p_matrix = (matrix_t *)malloc(sizeof(matrix_t));
    p_matrix->row = row;
    p_matrix->col = col;

    p_matrix->array  = (float **)malloc(row * sizeof(float*));
    for(int i = 0; i < row; i++) {
        p_matrix->array[i] = (float *)malloc(col * sizeof(float));
    }
    return p_matrix;
}

/*FUNCTION==========================================================
Function name: input_number_of_array
Description: Enter the number of matrix row and column
===================================================================*/
void input_number_of_array( int *row, int *col) {
    printf("Enter row of matrix: ");
    *row = get_input_int();
    printf("Enter column of matrix: ");
    *col = get_input_int();
}

/*FUNCTION==========================================================
Function name: create_matrix
Description: Enter input of matrix
===================================================================*/
void create_matrix(matrix_t *matrix) {
    int i = 0;
    int j = 0;
    for(i; i < matrix->row; i++) {
        for(j = 0; j < matrix->col; j++) {
            printf("Enter matrix[%d][%d]: ", i, j);
            matrix->array[i][j] = get_input_float();
        }
    }
}

/*FUNCTION==========================================================
Function name: print_matrix
Description: Print output of matrix
===================================================================*/
void print_matrix(matrix_t *matrix) {
    int i = 0;
    int j = 0;
    for(i = 0; i < matrix->row; i++) {
        for(j = 0; j < matrix->col; j++) {
            printf("%f ", matrix->array[i][j]);
        }
        printf("\n");
    }
}
/*FUNCTION==========================================================
Function name: calculate_sum_matrix
Description: Calculate sum of matrix A and matrix B
===================================================================*/
matrix_t* calculate_sum_matrix(matrix_t* p_matrix_a, matrix_t* p_matrix_b) {
    int i = 0;
    int j = 0;

    if(check_row_col_matrix(p_matrix_a->row, p_matrix_a->col, p_matrix_b->row, p_matrix_b->col, 1)) {
        return NULL;
    }

    matrix_t* p_sum = init_matrix(p_matrix_a->row,p_matrix_a->col);
    for(i = 0; i < p_matrix_a->row; i++) {
        for(j = 0; j < p_matrix_a->col; j++) {
            p_sum->array[i][j] = p_matrix_a->array[i][j] + p_matrix_b->array[i][j];
        }
    }
    return p_sum;
}

/*FUNCTION==========================================================
Function name: calculate_product_matrix
Description: Calculate product of matrix A and matrix B
===================================================================*/
matrix_t* calculate_product_matrix(matrix_t* p_matrix_a, matrix_t* p_matrix_b) { 
    int i = 0;
    int j = 0;
    if(check_row_col_matrix(p_matrix_a->row, p_matrix_a->col, p_matrix_b->row, p_matrix_b->col, 0)) {
        return NULL;
    }

    matrix_t* p_product_matrix = init_matrix(p_matrix_a->row,p_matrix_b->col);
    for(i = 0; i < p_matrix_a->row ; i++) {
        for(j = 0; j < p_matrix_b->col; j++) {
            p_product_matrix->array[i][j] = 0;
            for(int k = 0; k < p_matrix_a->col; k++) {
                p_product_matrix->array[i][j] += (p_matrix_a->array[i][k] * p_matrix_b->array[k][j]);
            }
        }
    }
    return p_product_matrix;
}

