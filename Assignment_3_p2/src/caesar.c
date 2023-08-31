#include "caesar.h"

double validate_num_input()
{
    char input_string[20] = {0};
    double input = -1;
    char *p_end;
    while (1)
    {
        __fpurge(stdin);
        scanf("%19s", input_string);
            long long intPart = strtoll(input_string, &p_end, 10);
            if (p_end != input_string && *p_end == '\0' && intPart >= 0 && intPart < 26)
            {
                input = intPart;
                return input;
            }
        printf("\nWARNING: ");
        printf(">> Only input is integer bigger than 0. Please enter again: ");
    }
    return input;
}

int input_shift(int shift)
{
    printf("Enter shift: ");
    shift = validate_num_input();
    return shift;
}

// Check if the file name contains any invalid characters
static bool is_invalid_file_name(const char *file_name)
{
    const char *invalid_chars = "\\/:*?\"<>|";
    for (int i = 0; i < strlen(invalid_chars); i++) {
        if (strchr(file_name, invalid_chars[i]) != NULL) {
            return false;
        }
    }
    return true;
}

//check file output is existed in folder
static bool is_exist_out_file(char* file_name)
{
    char ch;
    FILE *fp;
    fp = fopen(file_name, "r");
    if (fp == NULL)
    {
        printf(">> Create a output file success!!\n");
        return true;
    }
    else 
    {
        printf("Do you want to append output file (Y) or (N)? \n");
        printf("You choose: ");
        ch = getchar();
        if(ch == 'Y')
        {
            printf(">> Append output file success!!\n");
            return true;
        }
    }
    printf(">> This file is existed in folder. Please enter other output file!!\n");
    if(fp!= NULL) 
    {
        fclose(fp);
    }
    return false;
}

//check length of output name and check name of ouput have no " \/:*?\"<>| "
static bool is_over_range(char* file_name){
    bool valid_input;
    bool check_exist_file = false;
    if(strlen(file_name) > MAX_FILE_NAME){
        printf(">> File name too long. Please enter a shorter file name.\n");
        return check_exist_file;
    } 

    valid_input = is_invalid_file_name(file_name);
    if (!valid_input)
    {
        printf(">> Invalid input. Do not enter: \\/:*?\"<>| \n");
        return check_exist_file;
    }
    else
    {
        check_exist_file = is_exist_out_file(file_name);
    }
    return check_exist_file;
}

//check if enter "/////////" => false
static bool check_digit(char* file_name){
    int i = 0;
    for(i; i < strlen(file_name); i++){
        if(file_name[i] != '\\' && file_name[i] != '/'){
            return true;
        }
    }
    return false;
}

//check file input is existed in folder
static bool is_exist_input_file(char* file_name)
{
    FILE *fp;
    fp = fopen(file_name, "r");
    if (fp == NULL  || !check_digit(file_name))
    {
        printf(">> WARNING: File does not exsit. Please check folder!!\n");
        return false;
    }
    printf(">> Open file successful!!\n");
    fclose(fp);
    return true;
}

//check file exist in folder
static bool check_file_exist(char* file_name, bool check_in_out){
    bool check;
    if(check_in_out){
        check = is_exist_input_file(file_name);
    }
    else{
        check = is_exist_out_file(file_name);
    }
    return check;
}
//enter name of file
static void get_file_name(char* file_name, bool flag_check_input_output){
    __fpurge(stdin);
    if(flag_check_input_output){
        printf("Enter your input file name: ");
    }
    else{
        printf("Enter your output file name: ");
    }
    fgets(file_name, MAX_FILE_NAME, stdin);
    file_name[strcspn(file_name, "\n")] = '\0';
}

//enter input file and check name is validate
void input_file(char *file_name)
{
    bool is_file_exist = false;
    do {
        get_file_name(file_name, 1);
        is_file_exist = check_file_exist(file_name, 1);
    } while (!is_file_exist || strlen(file_name) > MAX_FILE_NAME);
}

void encrypt(char *file_name, int shift, bool flag, char* output_file_name)
{
    char ch;
    int temp = shift;

    FILE *input_file = fopen(file_name, "rb");
    FILE *output_file = fopen(output_file_name, "w");

    if (!flag)
    {
        temp = 26 - shift;
    }

    while ((ch = fgetc(input_file)) != EOF)
    {
        if (isalpha(ch))
        {
            char base = isupper(ch) ? 'A' : 'a';
            ch = (ch - base + temp) % 26 + base;
        }
        fputc(ch, output_file);
        putchar(ch);
    }

    fclose(input_file);
    fclose(output_file);
}
// Function to decrypt the content of a file using Caesar cipher
void decrypt(char *file_name, int shift, bool flag, char* output_file_name)
{
    encrypt(file_name, shift, 0, output_file_name);
}

void output_file(char* output_file_name)
{
    bool is_file_exist = false;
    do {
        get_file_name(output_file_name, 0);
        is_file_exist = is_over_range(output_file_name); 
        
    } while (!is_file_exist || strlen(output_file_name) > MAX_FILE_NAME);
}

void change_output_file(char* output_file_name)
{
    output_file(output_file_name);
    
}
