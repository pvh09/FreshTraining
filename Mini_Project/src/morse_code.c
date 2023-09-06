#include "morse_code.h"
#include "binary_tree.h"

char* map_morse_code(char character) {
    switch (character) {
        case 'A':
            return ".-";
        case 'B':
            return "-...";
        case 'C':
            return "-.-.";
        case 'D':
            return "-..";
        case 'E':
            return ".";
        case 'F':
            return "..-.";
        case 'G':
            return "--.";
        case 'H':
            return "....";
        case 'I':
            return "..";
        case 'J':
            return ".---";
        case 'K':
            return "-.-";
        case 'L':
            return ".-..";
        case 'M':
            return "--";
        case 'N':
            return "-.";
        case 'O':
            return "---";
        case 'P':
            return ".--.";
        case 'Q':
            return "--.-";
        case 'R':
            return ".-.";
        case 'S':
            return "...";
        case 'T':
            return "-";
        case 'U':
            return "..-";
        case 'V':
            return "...-";
        case 'W':
            return ".--";
        case 'X':
            return "-..-";
        case 'Y':
            return "-.--";
        case 'Z':
            return "--..";
        default:
            return ""; // Return an empty string for characters not in the Morse code mapping
    }
}

tree_node_t* build_morse_code_tree() {
    tree_node_t* root = create_node('\0');
    char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    // Loop through the characters array and insert into the tree
    for (int i = 0; characters[i] != '\0'; i++) {
        insert(root, characters[i], map_morse_code(characters[i]));
    }

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

void encode(tree_node_t* root, char character, FILE* output) {
    if (root == NULL || character == ' ') {
        return; // Invalid character or space, do nothing
    }

    if (isalpha(character)) {
        character = toupper(character); // Convert character to uppercase
        tree_node_t* current = root;
        while (current != NULL && current->data != character) {
            if (character < current->data) {
                fprintf(output, "."); // Dot for left traversal
                current = current->p_left;
            } else {
                fprintf(output, "-"); // Dash for right traversal
                current = current->p_right;
            }
        }

        if (current != NULL) {
            fprintf(output, " "); // Space to separate Morse code characters
        }
    }
}

void encodeText(tree_node_t* root, const char* text, FILE* output) {
    if (root == NULL || text == NULL) {
        return; // Invalid parameters
    }

    for (int i = 0; text[i] != '\0'; i++) {
        encode(root, text[i], output);
    }
}

// Function to free the memory of the Morse code tree
void freeMorseCodeTree(tree_node_t* root) {
    if (root == NULL) {
        return;
    }

    freeMorseCodeTree(root->p_left);
    freeMorseCodeTree(root->p_right);
    free(root);
}

// Function to open input and output files and perform encoding
int encodeFromFile(const char* inputFileName, const char* outputFileName, tree_node_t* root) {
    FILE* input = fopen(inputFileName, "r");
    if (input == NULL) {
        printf("Unable to open input file: %s\n", inputFileName);
        freeMorseCodeTree(root);
        return 1; // Exit with an error code
    }

    // Open the output file for writing
    FILE* output = fopen(outputFileName, "w");
    if (output == NULL) {
        printf("Unable to open output file: %s\n", outputFileName);
        fclose(input);
        freeMorseCodeTree(root);
        return 1; // Exit with an error code
    }

    char text[1000];
    while (fgets(text, sizeof(text), input) != NULL) {
        // Remove the newline character from the input
        text[strcspn(text, "\n")] = '\0';

        // Encode the text to Morse code and write to the output file
        encodeText(root, text, output);

        // Add a newline character after each line
        fprintf(output, "\n");
    }

    // Close the input and output files
    fclose(input);
    fclose(output);

    // Free the Morse code tree
    freeMorseCodeTree(root);

    return 0;
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