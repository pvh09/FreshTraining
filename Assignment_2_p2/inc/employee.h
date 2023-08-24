#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
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
    struct Employee* next;
};

typedef struct Date Date;
typedef struct Employee Employee;

void input_number_of_employee( int *number);

Employee* init_employee(int number);

Employee* create_employee(Employee *emp, int number);

void insert_employee(Employee** head, Employee* new_employee);

Employee* input_employee_infomation_list(int number, Employee** head);

void print_employee_table(Employee* head);

void free_employee_list(Employee* head);

void add_employee(Employee** employees);

void remove_employee_by_id(struct Employee** head);

void remove_employee_by_full_name(Employee** head);

double validate_num_input(bool flag);

void sort_emp_increase_salary(Employee** head);

void sort_emp_decrease_salary(Employee** head);

void sort_emp_alphabet_full_name(Employee** head);

#endif