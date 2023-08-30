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

static void is_alpha_num(char* file_name){
// Check if the input contains only numbers and alphabets
    int valid_input = 1;
    for (int i = 0; file_name[i] != '\0'; i++)
    {
        if (!isalnum(file_name[i]) && file_name[i] != '.')
        {
            valid_input = 0;
            break;
        }
    }
    if (!valid_input)
    {
        printf(">> Invalid input. Please use only numbers and alphabets.\n");
    }
    
    if(strlen(file_name) > 10){
        printf(">> File name too long. Please enter a shorter file name.\n");
    }    
}

static bool check_file_exist(char* file_name){
    FILE *fp;
    fp = fopen(file_name, "r");
    if (fp == NULL)
    {
        printf(">> WARNING: File does not exsit. Please check folder!!\n");
        return false;
    }
    printf(">> SUCCESS: File is existed in folder\n");
    fclose(fp);
    return true;
}

static void get_file_name(char* file_name){
    __fpurge(stdin);
    printf("Enter your file name: ");
    fgets(file_name, MAX_FILE_NAME, stdin);
    file_name[strcspn(file_name, "\n")] = '\0';
}

void input_file(char *file_name)
{
    bool is_file_exist = false;
    do {
        get_file_name(file_name);
        is_alpha_num(file_name); // check input is alpha and number
        is_file_exist = check_file_exist(file_name);
        
    } while (!isalnum(file_name[0]) || strlen(file_name) > 10 || !is_file_exist);
}

void calculate_encrypt(FILE* input_file, FILE* output_file, bool flag, int shift){
    int temp = shift;
    char ch;
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
}

void encrypt(char *file_name, int shift, bool flag)
{
    int temp = shift;

    FILE *input_file = fopen(file_name, "rb");
    FILE *output_file = fopen("output.txt", "a");

    calculate_encrypt(input_file, output_file, 1, shift);
    
    fclose(input_file);
    fclose(output_file);
}
// Function to decrypt the content of a file using Caesar cipher
void decrypt(char *file_name, int shift)
{
    encrypt(file_name, shift, 0);
}

void output_file(char* output_file_name)
{
    bool is_file_exist = false;
    do {
        get_file_name(output_file_name);
        is_alpha_num(output_file_name); // check input is alpha and number
        //is_file_exist = check_file_exist(file_name);
        
    } while (!isalnum(output_file_name[0]) || strlen(output_file_name) > 10);
}

void change_new_output_file(char* output_file_name, int shift)
{
    output_file(output_file_name);
    FILE *new_output_file = fopen(output_file_name, "a");
    
}
