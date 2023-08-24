#include "employee.h"

void sort_menu(Employee** employees){

    int choice;
    do {
        printf("\n------------ SORT EMPLOYEE ----------------\n");
        printf("    1. Sort employee by increasing salary\n");
        printf("    2. Sort employee by decreasing salary\n");
        printf("    3. Sort employee by full name alphabetically\n");
        printf("    4. Exit sorting\n");
        printf("Enter your choice: ");
        choice = validate_num_input(0);

        switch (choice) {
            case 1:
                sort_emp_increase_salary(employees);
                break;
            case 2:
                sort_emp_decrease_salary(employees);
                break;
            case 3:
                sort_emp_alphabet_full_name(employees);
                break;
            case 4:
                printf("Exiting sorting. Back to program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);
}

int main(){
    Employee* employees = NULL;

    int choice;
    do {
        printf("\n---------- Employee Management System -----------\n");
        printf("    1. Add Employee\n");
        printf("    2. Remove Employee by ID\n");
        printf("    3. Remove Employee by Full Name\n");
        printf("    4. Show Employees\n");
        printf("    5. Sorting employee\n");
        printf("    6. Exit\n");
        printf("Enter your choice: ");
        choice = validate_num_input(0);

        switch (choice) {
            case 1:
                add_employee(&employees);
                break;
            case 2:
                remove_employee_by_id(&employees);
                break;
            case 3:
                remove_employee_by_full_name(&employees);
                break;
            case 4:
                print_employee_table(employees);
                break;
            case 5:
                sort_menu(&employees);
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 6);
    free_employee_list(employees);
    return 0;
}