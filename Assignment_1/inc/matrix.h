#ifndef _MATRIX_H_
#define _MATRIX_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>

typedef struct
{
    float **array;
    int row;
    int col;
} matrix_t;

void input_number_of_array(int *row, int *col);

/*!
 * @brief <Initialize dynamic memory for matrix>
 *
 * @param  row <matrix row>
 *
 * @param  col <matrix column>
 *
 * @param *p_matrix [In] <pointer point to struct Matrix of the matrix>
 */
matrix_t *init_matrix(int row, int col);

/*!
 * @brief <Print the matrix to the terminal>
 *
 * @param *p_matrix [In] <pointer point to struct Matrix of the matrix>
 *
 *return None
 */
void print_matrix(matrix_t *matrix);

/*!
 * @brief <Calculate sum of matrix A and matrix B>
 *
 * @param *p_matrix_a <pointer elements of matrix A>
 *
 * @param *p_matrix_b <Inpointer elements of matrix B>
 */
matrix_t *calculate_sum_matrix(matrix_t *p_matrix_a, matrix_t *p_matrix_b);

/*!
 * @brief <release memory>
 *
 * @param *p_matrix_a <pointer elements of matrix A>
 *
 * @param *p_matrix_b <pointer elements of matrix B>
 */
matrix_t *calculate_product_matrix(matrix_t *p_matrix_a, matrix_t *p_matrix_b);

/*!
 * @brief <release memory>
 *
 * @param *p_matrix_a <pointer elements of matrix>
 */
void free_matrix(matrix_t *matrix);

/*!
* @brief <check validate mumber of row, column>
*
@param *inputRequest <>
*/
#endif
