#include "employee.h"

/*FUNCTION==========================================================
Function name: validate_num_input
Description: validate input data from keyboard
====================void free_matrix(matrix_t *matrix);===============================================*/
//flag: 1 -- accept input is int, double
//      0 -- accept input is unsigned int
double validate_num_input(bool flag) {
    char input_string[20] = {0};
    double input = -1;
    char *pEnd;
    while (1) {
        __fpurge(stdin);
        scanf("%19s", input_string);
        if (flag == 1) {
            input = strtod(input_string, &pEnd);
            if (*pEnd == '\0') {
                return input;
            }
        } else if (flag == 0) {
            long long intPart = strtoll(input_string, &pEnd, 10);
            if (pEnd != input_string && *pEnd == '\0' && intPart > 0) {
                input = intPart;
                return input;
            }
        }
        printf("\nWARNING: ");
        if (flag == 1) {
            printf("Only input is integer or double. Please enter again: ");
        } else if (flag == 0) {
            printf("Only input is integer bigger than 0. Please enter again: ");
        }
    }
    return input;
}

// Function to validate input and return only string containing alphabetic characters
static char* validate_string_input() {
    char input_string[51] = {0}; // Increased buffer size to 51 characters
    char *result = NULL;

    while (1) {
        __fpurge(stdin);
        fgets(input_string, sizeof(input_string), stdin);
        input_string[strcspn(input_string, "\n")] = '\0'; // Remove newline character
        if (strlen(input_string) > 50 || strlen(input_string) ==0) {
            printf("\nWARNING: Input exceeds the limit of 50 characters or no detect input. Please enter again: ");
            continue;
        }
        
        int valid_input = 1;
        for (int i = 0; input_string[i] != '\0'; i++) {
            if (!isalpha(input_string[i]) && !isspace(input_string[i])) {
                valid_input = 0;
                break;
            }
        }
        
        if (valid_input) {
            result = strdup(input_string);
            return result;
        } else {
            printf("\nWARNING: Only input is text. Please enter again: ");
        }
    }
    return result;
}

static int check_unique_id(Employee **head) {
    int new_id;
    bool is_unique = false;
    do {
        printf("ID: ");
        new_id = (int)validate_num_input(0);
        // Check if the ID already exists
        Employee *current = *head;
        is_unique = true;

        while (current != NULL) {
            if (current->id == new_id) {
                printf("Employee with ID %d already exists. Please enter a different ID.\n", new_id);
                is_unique = false;
                break;
            }
            current = current->next;
        }

    } while (!is_unique);

    return new_id;
}

static bool is_valid_date(Date date) {
    if (date.year < 1900 || date.year > 2100) {
        return false;
    }
    int maxDays = 31;
    if (date.month < 1 || date.month > 12) {
        return false;
    }
    if (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11) {
        maxDays = 30;
    } else if (date.month == 2) {
        if ((date.year % 4 == 0 && date.year % 100 != 0) || (date.year % 400 == 0)) {
            maxDays = 29;
        } else {
            maxDays = 28;
        }
    }
    return date.day >= 1 && date.day <= maxDays;
}

void input_number_of_employee(int *number){
    printf("Enter the number of employees (1 - %d): ", MAX_EMPLOYEES);
    *number = validate_num_input(0); //0: only input is unsigned int

    while (*number < 1 || *number > MAX_EMPLOYEES)
    {
        printf("Invalid number of employee (employee < 50).\n");
        *number = validate_num_input(0);
    }
}

Employee* init_employee(int number){
    Employee* list_employee = (Employee*)malloc(number * sizeof(Employee));
    return list_employee;
}

Employee* create_employee(Employee *emp, int number){
    Employee* new_employee = init_employee(number);
    if (new_employee == NULL) {
        return NULL;
    }
    new_employee->id = emp->id;
    
    if (emp->full_name != NULL) {
        new_employee->full_name = strdup(emp->full_name);
    } else {
        new_employee->full_name = NULL;
    }

    if (emp->department != NULL) {
        new_employee->department = strdup(emp->department);
    } else {
        new_employee->department = NULL;
    }
    new_employee->salary = emp->salary;
    new_employee->start_date = emp->start_date;
    new_employee->next = NULL;
    
    return new_employee;
}

void insert_employee(Employee** head, Employee* new_employee) {
    if (*head == NULL) {
        *head = new_employee;
    } else {
        new_employee->next = *head;
        *head = new_employee;
    }
}

Employee* input_employee_infomation_list(int number, Employee** head) {
    Employee* new_employee = (Employee*)malloc(sizeof(Employee));
    bool flag_check_id = 0;

    printf("Enter information for employee #%d:\n", number + 1);
    int new_id = (int)check_unique_id(head);
    new_employee->id = new_id;

    __fpurge(stdin);
    printf("Full Name: ");
    __fpurge(stdin);
    new_employee->full_name = (char*)malloc(10 * sizeof(char)); // Adjust the size as needed
    new_employee->full_name = validate_string_input();
    __fpurge(stdin);
    
    printf("Department: ");
    __fpurge(stdin);
    new_employee->department = (char*)malloc(100 * sizeof(char)); // Adjust the size as needed
    scanf(" %[^\n]", new_employee->department);
    printf("Salary: ");
    new_employee->salary = validate_num_input(0);  // Assuming 1 means input can be double
    do {
        printf("Start Date (day month year): ");
        __fpurge(stdin);
        scanf("%d %d %d", &new_employee->start_date.day, &new_employee->start_date.month, &new_employee->start_date.year);
    } while (!is_valid_date(new_employee->start_date));

    new_employee->next = NULL;
    return new_employee;
}

void print_employee_table(Employee* head) {
    
    printf("\n%-5s %-20s %-15s %-10s %-12s\n", "ID", "Full Name", "Department", "Salary", "Start Date");
    printf("------------------------------------------------------------------\n");
    while (head != NULL) {
        printf("%-5d %-20s %-15s %-10.2lf %02d/%02d/%04d\n", head->id, head->full_name, head->department, head->salary,
               head->start_date.day, head->start_date.month, head->start_date.year);
        head = head->next;
    }
}

void free_employee_list(Employee* head) {
    while (head != NULL) {
        Employee* temp = head;
        head = head->next;
        if (temp->full_name != NULL) {
            free(temp->full_name);
        }
        if (temp->department != NULL) {
            free(temp->department);
        }
        
        free(temp);
    }
}

void add_employee(Employee** employees){
    int number_employee = 0;
    input_number_of_employee(&number_employee);
    for (int i = 0; i < number_employee; i++) {
        Employee* new_employee = input_employee_infomation_list(i, employees);
        insert_employee(employees, new_employee);
    }
}

void remove_employee_by_id(Employee** head) {
    struct Employee* current = *head;
    struct Employee* previous = NULL;
    int remove_id = 0;
    printf("Enter employee ID need to remove: ");
    remove_id = (int)validate_num_input(0);
    while (current != NULL) {
        if (current->id == remove_id) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("Employee with ID %d has been removed.\n", remove_id);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Employee with ID %d not found.\n", remove_id);
}

void remove_employee_by_full_name(Employee** head) {
    Employee* current = *head;
    Employee* previous = NULL;
    char* full_name = (char*)malloc(100 * sizeof(char));

    printf("Full name of employee need to remove: ");
    full_name = validate_string_input();
    int match_count = 0; // To count the number of employees with the same full name

    while (current != NULL) {
        if (strcmp(current->full_name, full_name) == 0) {
            match_count++;
        }
        current = current->next;
    }

    if (match_count == 0) {
        printf("No employee with full name '%s' found.\n", full_name);
    } else if (match_count == 1) {
        // Remove the employee with the given full name
        current = *head;
        while (current != NULL) {
            if (strcmp(current->full_name, full_name) == 0) {
                if (previous == NULL) {
                    *head = current->next;
                } else {
                    previous->next = current->next;
                }
                printf("Employee with full name '%s' and ID %d has been removed.\n", full_name, current->id);
                free(current);
                break;
            }
            previous = current;
            current = current->next;
        }
    } else {
        // Remove employees with the given full name by their IDs
        printf("NOTICE: There are %d employees in list!!\n", match_count);
        printf("WARNING: Must be delete employee by ID: \n");
        remove_employee_by_id(head);
    }
}

static void swap_employee(Employee** a, Employee** b) {
    Employee* temp = *a;
    *a = *b;
    *b = temp;
}

void sort_emp_increase_salary(Employee** head){
    for (Employee* i = *head; i != NULL; i = i->next) {
        for (Employee* j = i->next; j != NULL; j = j->next) {
            if (j->salary > i->salary) {
                swap_employee(&i, &j);
            }
        }
    }
    //print_employee_table(head);
}

void sort_emp_decrease_salary(Employee** head){
    for (Employee* i = *head; i != NULL; i = i->next) {
        for (Employee* j = i->next; j != NULL; j = j->next) {
            if (j->salary < i->salary) {
                swap_employee(&i, &j);
            }
        }
    }
    //print_employee_table(head);
}

void sort_emp_alphabet_full_name(Employee** head){
    for (Employee* i = *head; i != NULL; i = i->next) {
        for (Employee* j = i->next; j != NULL; j = j->next) {
            if (strcmp(j->full_name, i->full_name) < 0) {
                swap_employee(&i, &j);
            }
        }
    }
    //print_employee_table(head);
}

