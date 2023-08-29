#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define _POSIX_C_SOURCE 200809L
#include <string.h>
#include <limits.h>
#include <stdio_ext.h> // __fpurge(stdin);

#define MAX_EMPLOYEES 50

struct Date {
    int day;
    int month;
    int year;
};

struct Employee {
    int id;
    char* full_name;
    char* department;
    double salary;
    struct Date start_date;
};

typedef enum {
    TMP,
    ADD_EMPLOYEE,
    REMOVE_BY_ID,
    REMOVE_BY_FULL_NAME,
    SHOW_EMPLOYEE,
    SORT_OPTION,
    EXIT_PROGRAM
}option_t;

typedef enum {
    TEMP,
    SORT_BY_SALARY_INCREASING,
    SORT_BY_SALARY_DERCEASING,
    SORT_BY_ALPHABET_FULL_NAME,
    EXIT_SORT
}option_sort;

typedef struct Date Date;
typedef struct Employee Employee;

struct node {
    Employee* employee_info;
    struct node* next;
};

typedef struct node employee_list;

/*!
* @brief <Get the number of employee input from keyboard>
*
* @param *number [In/Out] <pointer point to the employee number>
*
* @return None
*/
void input_number_of_employee( int *number);

/*!
* @brief <Insert new employee to list employee>
*
* @param **list_employee [In] <pointer to pointer point to the head node of employee linked list>
*
* @param *p_new_employee [In/Out] <pointer point to the head node of employee linked list>
*
* @return None
*/
void insert_employee(employee_list** list_employee, Employee *p_new_employee);

/*!
 * @brief Enter information of a new employee into the employee list.
 *
 * This function prompts the user to input information for a new employee and adds
 * the employee to the linked list.
 *
 * @param[in] number - Employee number.
 * 
 * @param[in,out] list_employee - Pointer to a pointer pointing to the head node of the employee linked list.
 *
 * @return Pointer to the new employee structure.
 */
Employee* input_employee_infomation_list(int number, employee_list** list_employee);

/*!
 * @brief Print the table of employees' information.
 *
 * This function prints the information of all employees in a tabular format.
 *
 * @param[in] list_head - Pointer to the head node of the employee linked list.
 *
 * @return None.
 */
void print_employee_table(employee_list* list_head);

/*!
 * @brief Free the memory occupied by the employee linked list.
 *
 * This function releases the memory occupied by each employee node and the linked list.
 *
 * @param[in] head - Pointer to the head node of the employee linked list.
 *
 * @return None.
 */
void free_employee_list(employee_list* head);

/*!
 * @brief Add a new employee to the list.
 *
 * This function adds a new employee to the employee list.
 *
 * @param[in,out] employees - Pointer to a pointer pointing to the head node of the employee linked list.
 *
 * @return None.
 */
void add_employee(employee_list** employees);

/*!
 * @brief Remove an employee by their ID.
 *
 * This function removes an employee from the list based on their ID.
 *
 * @param[in,out] head - Pointer to a pointer pointing to the head node of the employee linked list.
 *
 * @return None.
 */
void remove_employee_by_id(employee_list** head);

/*!
 * @brief Remove employees by their full name.
 *
 * This function removes employees from the list based on their full name.
 *
 * @param[in,out] head - Pointer to a pointer pointing to the head node of the employee linked list.
 *
 * @return None.
 */
void remove_employee_by_full_name(employee_list** head);

/*!
 * @brief Validate and input a numerical value.
 *
 * This function validates and inputs a numerical value from the user.
 *
 * @param[in] flag - Boolean flag to determine whether to validate for non-negative input.
 *
 * @return The validated numerical value.
 */
double validate_num_input(bool flag);

/*!
 * @brief Sort the employee list using merge sort.
 *
 * This function sorts the employee list using merge sort based on the provided comparison function.
 *
 * @param[in,out] head - Pointer to a pointer pointing to the head node of the employee linked list.
 * 
 * @param[in] compare - Pointer to the comparison function used for sorting.
 *
 * @return None.
 */
void merge_sort(employee_list** head, int (*compare)(const void*, const void*));

/*!
 * @brief Compare function for sorting employees by increasing salary.
 *
 * This function is used as a comparison function for sorting employees by increasing salary.
 *
 * @param[in] left - Pointer to the left employee to be compared.
 * 
 * @param[in] right - Pointer to the right employee to be compared.
 *
 * @return Comparison result.
 */
int compare_increase_salary(const void* left, const void* right);

/*!
 * @brief Compare function for sorting employees by decreasing salary.
 *
 * This function is used as a comparison function for sorting employees by decreasing salary.
 *
 * @param[in] left - Pointer to the left employee to be compared.
 * 
 * @param[in] right - Pointer to the right employee to be compared.
 *
 * @return Comparison result.
 */
int compare_decrease_salary(const void* left, const void* right);

/*!
 * @brief Compare function for sorting employees by full name alphabetically.
 *
 * This function is used as a comparison function for sorting employees by full name alphabetically.
 *
 * @param[in] left - Pointer to the left employee to be compared.
 * 
 * @param[in] right - Pointer to the right employee to be compared.
 *
 * @return Comparison result.
 */
int compare_by_name(const void* left, const void* right);
#endif