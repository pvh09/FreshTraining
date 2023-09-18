#include "employee.h"

e_employee_list *list_employee = NULL;

void sort_menu(e_employee_list *list_employee)
{
    option_sort choice = 0;
    do
    {
        printf("\n------------ SORT EMPLOYEE ----------------\n");
        printf("    1. Sort employee by increasing salary\n");
        printf("    2. Sort employee by decreasing salary\n");
        printf("    3. Sort employee by full name alphabetically\n");
        printf("    4. Exit sorting\n");
        printf("Enter your choice: ");
        choice = validate_num_input(0);

        switch (choice)
        {
        case SORT_BY_SALARY_INCREASING:
            merge_sort(&list_employee, compare_increase_salary);
            print_employee_table(list_employee);
            break;
        case SORT_BY_SALARY_DERCEASING:
            merge_sort(&list_employee, compare_decrease_salary);
            print_employee_table(list_employee);
            break;
        case SORT_BY_ALPHABET_FULL_NAME:
            merge_sort(&list_employee, compare_by_name);
            print_employee_table(list_employee);
            break;
        case EXIT_SORT:
            printf("Exiting sorting. Back to program.\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);
}

int main()
{
    option_t choice;
    do
    {
        printf("\n---------- Employee Management System -----------\n");
        printf("    1. Add Employee\n");
        printf("    2. Remove Employee by ID\n");
        printf("    3. Remove Employee by Full Name\n");
        printf("    4. Show Employees\n");
        printf("    5. Sorting employee\n");
        printf("    6. Exit\n");
        printf("Enter your choice: ");
        choice = validate_num_input(0);

        switch (choice)
        {
        case ADD_EMPLOYEE:
            add_employee(&list_employee);
            break;
        case REMOVE_BY_ID:
            remove_employee_by_id(&list_employee);
            break;
        case REMOVE_BY_FULL_NAME:
            remove_employee_by_full_name(&list_employee);
            break;
        case SHOW_EMPLOYEE:
            print_employee_table(list_employee);
            break;
        case SORT_OPTION:
            sort_menu(list_employee);
            break;
        case EXIT_PROGRAM:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 6);
    free_employee_list(list_employee);
    return 0;
}