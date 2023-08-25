#include "employee.h"

char *strdup(const char *src) {
    char *dst = malloc(strlen (src) + 1);
    if (dst == NULL) return NULL;          
    strcpy(dst, src);                      
    return dst;                            
}

// flag: 1 -- accept input is int, double
//       0 -- accept input is unsigned int
double validate_num_input(bool flag)
{
    char input_string[20] = {0};
    double input = -1;
    char *p_end;
    while (1)
    {
        __fpurge(stdin);
        scanf("%19s", input_string);
        if (flag == 1)
        {
            input = strtod(input_string, &p_end);
            if (*p_end == '\0')
            {
                return input;
            }
        }
        else if (flag == 0)
        {
            long long intPart = strtoll(input_string, &p_end, 10);
            if (p_end != input_string && *p_end == '\0' && intPart > 0)
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
            printf("Only input is integer bigger than 0. Please enter again: ");
        }
    }
    return input;
}

// Function to validate input and return only string containing alphabetic characters
static char* validate_string_input() {
    char input_string[MAX_EMPLOYEES] = {0};
    char *result = NULL;

    while (1) {
        __fpurge(stdin);
        fgets(input_string, sizeof(input_string), stdin);
        input_string[strcspn(input_string, "\n")] = '\0'; 
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

static int check_unique_id(Employee **p_head) {
    int new_id;
    bool is_unique = false;
    do {
        printf("ID: ");
        new_id = (int)validate_num_input(0);
        Employee *p_current = *p_head;
        is_unique = true;

        while (p_current != NULL)
        {
            if (p_current->id == new_id)
            {
                printf("Employee with ID %d already exists. Please enter a different ID.\n", new_id);
                is_unique = false;
                break;
            }
            p_current = p_current->next;
        }

    } while (!is_unique);

    return new_id;
}

static bool is_valid_date(Date date)
{
    if (date.year < 1900 || date.year > 2100)
    {
        return false;
    }
    int max_days = 31;
    if (date.month < 1 || date.month > 12)
    {
        return false;
    }
    if (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11)
    {
        max_days = 30;
    }
    else if (date.month == 2)
    {
        if ((date.year % 4 == 0 && date.year % 100 != 0) || (date.year % 400 == 0))
        {
            max_days = 29;
        }
        else
        {
            max_days = 28;
        }
    }
    return date.day >= 1 && date.day <= max_days;
}

void input_number_of_employee(int *p_number)
{
    printf("Enter the number of p_employees (1 - %d): ", MAX_EMPLOYEES);
    *p_number = validate_num_input(0); // 0: only input is unsigned int

    while (*p_number < 1 || *p_number > MAX_EMPLOYEES) {
        printf("Invalid number of employee (employee < 50).\n");
        *p_number = validate_num_input(0);
    }
}

Employee *init_employee(int number)
{
    Employee *p_list_employee = (Employee *)malloc(number * sizeof(Employee));
    return p_list_employee;
}

Employee *create_employee(Employee *p_emp, int number)
{
    Employee *p_new_employee = init_employee(number);
    if (p_new_employee == NULL)
    {
        return NULL;
    }
    p_new_employee->id = p_emp->id;

    if (p_emp->full_name != NULL) {
        p_new_employee->full_name = strdup(p_emp->full_name);
    }
    else {
        p_new_employee->full_name = NULL;
    }

    if (p_emp->department != NULL) {
        p_new_employee->department = strdup(p_emp->department);
    }
    else {
        p_new_employee->department = NULL;
    }
    p_new_employee->salary = p_emp->salary;
    p_new_employee->start_date = p_emp->start_date;
    p_new_employee->next = NULL;

    return p_new_employee;
}

void insert_employee(Employee **p_head, Employee *p_new_employee)
{
    if (*p_head == NULL)
    {
        *p_head = p_new_employee;
    }
    else
    {
        p_new_employee->next = *p_head;
        *p_head = p_new_employee;
    }
}

static void get_date_employee(Employee* p_employee){
    do
    {
        printf("Start Date (day month year): ");
        __fpurge(stdin);
        scanf("%d %d %d", &p_employee->start_date.day, &p_employee->start_date.month, &p_employee->start_date.year);
    } while (!is_valid_date(p_employee->start_date));

    p_employee->next = NULL;
    
}

Employee *input_employee_infomation_list(int number, Employee **p_head)
{
    Employee *p_new_employee = (Employee *)malloc(sizeof(Employee));
    if (p_new_employee == NULL) {
        return NULL;
    }

    printf("Enter information for employee #%d:\n", number + 1);
    int new_id = (int)check_unique_id(p_head);

    p_new_employee->id = new_id;
    printf("Full Name: ");
    p_new_employee->full_name = validate_string_input();

    printf("Department: ");
    p_new_employee->department = (char *)malloc(MAX_EMPLOYEES * sizeof(char));
    if (p_new_employee->department == NULL) {
        free(p_new_employee->full_name);
        free(p_new_employee);
        return NULL;
    }
    scanf(" %[^\n]", p_new_employee->department);

    printf("Salary: ");
    p_new_employee->salary = validate_num_input(0); // Assuming 0 means input can be double

    get_date_employee(p_new_employee);

    return p_new_employee;
}

void print_employee_table(Employee *p_head)
{

    printf("\n%-5s %-20s %-15s %-10s %-12s\n", "ID", "Full Name", "Department", "Salary", "Start Date");
    printf("------------------------------------------------------------------\n");
    while (p_head != NULL)
    {
        printf("%-5d %-20s %-15s %-10.2lf %02d/%02d/%04d\n", p_head->id, p_head->full_name, p_head->department, p_head->salary,
               p_head->start_date.day, p_head->start_date.month, p_head->start_date.year);
        p_head = p_head->next;
    }
}

void free_employee_list(Employee *p_head)
{
    while (p_head != NULL)
    {
        Employee *p_temp = p_head;
        p_head = p_head->next;
        if (p_temp->full_name != NULL)
        {
            free(p_temp->full_name);
        }
        if (p_temp->department != NULL)
        {
            free(p_temp->department);
        }

        free(p_temp);
        p_temp = NULL;
    }
}

void free_employee(Employee* p_current){
    if (p_current->full_name != NULL) {
        free(p_current->full_name);
    }
    if (p_current->department != NULL) {
        free(p_current->department);
    }
    free(p_current);
    p_current = NULL;
}

void add_employee(Employee **p_employees)
{
    int number_employee = 0;
    Employee *p_new_employee = NULL;
    input_number_of_employee(&number_employee);
    for (int i = 0; i < number_employee; i++)
    {
        p_new_employee = input_employee_infomation_list(i, p_employees);
        insert_employee(p_employees, p_new_employee);
    }
}

void remove_employee_by_id(Employee** p_head) {
    struct Employee* p_current = *p_head;
    struct Employee* previous = NULL;
    int remove_id = 0;
    printf("Enter employee ID need to remove: ");
    remove_id = (int)validate_num_input(0);
    while (p_current != NULL) {
        if (p_current->id == remove_id) {
            if (previous == NULL) {
                *p_head = p_current->next;
            } else {
                previous->next = p_current->next;
            }
            free_employee(p_current);
            printf("Employee with ID %d has been removed.\n", remove_id);
            return;
        }
        previous = p_current;
        p_current = p_current->next;
    }
    printf("Employee with ID %d not found.\n", remove_id);
}
    

static void check_full_name_remove(Employee* p_current, Employee** p_head, char* full_name){
// Remove the employee with the given full name
    Employee *p_previous = NULL;
    p_current = *p_head;
    while (p_current != NULL)
    {
        if (strcmp(p_current->full_name, full_name) == 0)
        {
            if (p_previous == NULL)
            {
                *p_head = p_current->next;
            }
            else
            {
                p_previous->next = p_current->next;
            }
            printf("Employee with full name '%s' and ID %d has been removed.\n", full_name, p_current->id);
            free_employee(p_current);
            break;
        }
        p_previous = p_current;
        p_current = p_current->next;
    }
}

static int count_employee(Employee *p_current, char *full_name){
    int match_count = 0;
    while (p_current != NULL)
    {
        if (strcmp(p_current->full_name, full_name) == 0)
        {
            match_count++;
        }
        p_current = p_current->next;
    }
    return match_count;
}

void remove_employee_by_full_name(Employee **p_head)
{
    Employee *p_current = *p_head;
    char *p_full_name;

    printf("Full name of employee need to remove: ");
    p_full_name = validate_string_input();
    int match_count = count_employee(p_current, p_full_name);

    if (match_count == 0) {
        printf("No employee with full name '%s' found.\n", p_full_name);
    }
    else if (match_count == 1) {
        check_full_name_remove(p_current, p_head, p_full_name);
    }
    else {
        printf("NOTICE: There are %d p_employees in list!!\n", match_count);
        printf("WARNING: Must be delete employee by ID: \n");
        remove_employee_by_id(p_head);
    }

    free(p_full_name);

}

static Employee *merge(Employee *left, Employee *right, int (*compare)(const void *, const void *))
{
    if (left == NULL)
    {
        return right;
    }
    if (right == NULL)
    {
        return left;
    }

    Employee *result = NULL;

    if (compare(left, right) <= 0)
    {
        result = left;
        result->next = merge(left->next, right, compare);
    }
    else
    {
        result = right;
        result->next = merge(left, right->next, compare);
    }

    return result;
}

// Comparison function for increasing salary
int compare_increase_salary(const void *p_a, const void *p_b)
{
    const Employee *p_emp1 = *(const Employee **)p_a;
    const Employee *p_emp2 = *(const Employee **)p_b;
    return (p_emp1->salary > p_emp2->salary) - (p_emp1->salary < p_emp2->salary);
}

// Comparison function for decreasing salary
int compare_decrease_salary(const void *p_a, const void *p_b)
{
    const Employee *p_emp1 = *(const Employee **)p_a;
    const Employee *p_emp2 = *(const Employee **)p_b;
    return (p_emp2->salary > p_emp1->salary) - (p_emp2->salary < p_emp1->salary);
}

// Comparison function for full name alphabetically
int compare_by_name(const void *p_a, const void *p_b)
{
    const Employee *p_emp1 = *(const Employee **)p_a;
    const Employee *p_emp2 = *(const Employee **)p_b;
    return strcmp(p_emp1->full_name, p_emp2->full_name);
}

void merge_sort(Employee **p_head, int (*compare)(const void *, const void *))
{
    if (*p_head == NULL || (*p_head)->next == NULL)
    {
        return;
    }
    Employee *p_current = *p_head;
    Employee *left = NULL;
    Employee *right = NULL;

    Employee *mid = *p_head;
    Employee *fast = (*p_head)->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            mid = mid->next;
            fast = fast->next;
        }
    }
    left = *p_head;
    right = mid->next;
    mid->next = NULL;

    merge_sort(&left, compare);
    merge_sort(&right, compare);

    *p_head = NULL;

    while (left != NULL && right != NULL)
    {
        Employee *p_temp;
        if (compare(&left, &right) <= 0) {
            p_temp = left;
            left = left->next;
        }
        else {
            p_temp = right;
            right = right->next;
        }

        if (*p_head == NULL) {
            *p_head = p_temp;
            p_current = *p_head;
        }
        else
        {
            p_current->next = p_temp;
            p_current = p_current->next;
        }
    }
    if (left != NULL){
        p_current->next = left;
    }
    else {
        p_current->next = right;
    }
}