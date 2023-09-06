#include "morse_code.h"

tree_node_t* build_morse_code_tree() {
    tree_node_t* root = create_node('\0');
    insert(root, 'A', ".-");
    insert(root, 'B', "-...");
    insert(root, 'C', "-.-.");
    insert(root, 'D', "-..");
    insert(root, 'E', ".");
    insert(root, 'F', "..-.");
    insert(root, 'G', "--.");
    insert(root, 'H', "....");
    insert(root, 'I', "..");
    insert(root, 'J', ".---");
    insert(root, 'K', "-.-");
    insert(root, 'L', ".-..");
    insert(root, 'M', "--");
    insert(root, 'N', "-.");
    insert(root, 'O', "---");
    insert(root, 'P', ".--.");
    insert(root, 'Q', "--.-");
    insert(root, 'R', ".-.");
    insert(root, 'S', "...");
    insert(root, 'T', "-");
    insert(root, 'U', "..-");
    insert(root, 'V', "...-");
    insert(root, 'W', ".--");
    insert(root, 'X', "-..-");
    insert(root, 'Y', "-.--");
    insert(root, 'Z', "--..");

    return root;
}

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

//check if enter "/////////" => false
static bool check_digit(char* file_name){
    int i = 0;
    for(i; i < strlen(file_name); i++){
        if(file_name[i] != '\\' && file_name[i] != '/' && file_name[i] != '.'){
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

void input_file(char *file_name)
{
    bool is_file_exist = false;
    do {
        get_file_name(file_name, 1);
        is_file_exist = check_file_exist(file_name, 1);
    } while (!is_file_exist || strlen(file_name) > MAX_FILE_NAME);
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

tree_node_t* create_node(char data) {
    tree_node_t* new_node = (tree_node_t*)malloc(sizeof(tree_node_t));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    new_node->data = data;
    new_node->p_left = NULL;
    new_node->p_right = NULL;
    return new_node;
}

void insert(tree_node_t* root, char character, char* code) {
    tree_node_t* current_node = root;

    for (int i = 0; code[i] != '\0'; i++) {
        if (code[i] == '.') {
            if (current_node->p_left == NULL) {
                current_node->p_left = (tree_node_t*)malloc(sizeof(tree_node_t));
                current_node->p_left->data = '\0'; // Initialize to null character
                current_node->p_left->p_left = NULL;
                current_node->p_left->p_right = NULL;
            }
            current_node = current_node->p_left;
        } else if (code[i] == '-') {
            if (current_node->p_right == NULL) {
                current_node->p_right = (tree_node_t*)malloc(sizeof(tree_node_t));
                current_node->p_right->data = '\0'; // Initialize to null character
                current_node->p_right->p_left = NULL;
                current_node->p_right->p_right = NULL;
            }
            current_node = current_node->p_right;
        }
    }
    current_node->data = character;
}



// morse code -> text
void decode_file(const char* input_file, const char* output_file, tree_node_t* root) {
    FILE* input = fopen(input_file, "r");
    if (input == NULL) {
        printf("Unable to open input file.\n");
        return;
    }

    FILE* output = fopen(output_file, "w");
    if (output == NULL) {
        printf("Unable to open output file.\n");
        fclose(input);
        return;
    }

    char line[512];  // Adjust the buffer size as needed
    while (fgets(line, sizeof(line), input) != NULL) {
        char* token = strtok(line, " \n");  // Tokenize based on space and newline
        while (token != NULL) {
            if (strcmp(token, "/") == 0) {
                // Replace "/" with a space in the output
                fprintf(output, " ");
            } else {
                char morse_code[10] = "";
                for (int i = 0; token[i] != '\0'; i++) {
                    if (token[i] == '.') {
                        strcat(morse_code, ".");
                    } else if (token[i] == '-') {
                        strcat(morse_code, "-");
                    }
                }

                // Decode the Morse code
                tree_node_t* current_node = root;
                for (int i = 0; morse_code[i] != '\0'; i++) {
                    if (morse_code[i] == '.') {
                        current_node = current_node->p_left;
                    } else if (morse_code[i] == '-') {
                        current_node = current_node->p_right;
                    }
                }
                fprintf(output, "%c", current_node->data);
            }

            token = strtok(NULL, " \n");  // Move to the next token
        }
        fprintf(output, " ");  // Add a space after each word
    }

    fclose(input);
    fclose(output);
}