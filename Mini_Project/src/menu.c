#include "menu.h"
#include "morse_code.h"
#include "file_handling.h"

static int flag_check_change_file_from_keyboard = 0;
static int flag_check_change_file = 0;

void data_from_file_menu(char *file_name, char *output_file_name)
{
    option_t choice;

    flag_check_change_file_from_keyboard = 0; // reset output file in keyboard because user switches to reading from the file
    if (flag_check_change_file == 0)
    {
        input_file(file_name);
        change_file(output_file_name);
    }
    system("clear");
    do
    {
        printf("\n***************************************\n");
        printf(">> You choose enter data from FILE\n");
        printf(">> Your input file name: %s\n", file_name);
        printf(">> Your output file name: %s", output_file_name);
        printf("\n=======================================");
        printf("\n----------------OPTION-----------------\n");
        printf("  1. Encode (convert text to morsecode)\n");
        printf("  2. Decode (convert morsecode to text)\n");
        printf("  3. Change input/output file\n");
        printf("  0. Exit\n");
        printf("\nEnter your choice: ");
        choice = validate_num_input();

        switch (choice)
        {
        case ENCODING:
            int result = encode_file(file_name, output_file_name);
            printf("Message: \n");
            read_and_print_file(output_file_name);
            if (result != 0)
            {
                printf("\n>> Error encoding file\n");
            }
            else
            {
                printf("\n>> File encoded successfully. Please check folder\n");
            }
            break;
        case DECODING:
            decode_file(file_name, output_file_name);
            printf("Message: ");
            read_and_print_file(output_file_name);
            printf("\n");
            break;
        case CHANGE_FILE:
            flag_check_change_file++;
            printf(">> New: \n");
            input_file(file_name);
            change_file(output_file_name);
            choice = 0;
            break;
        case EXIT:
            printf(">> Exit. Back to main program\n");
            return;
        default:
            printf(">> Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);
}

void data_from_keyboard_menu(char *output_file_name)
{
    option_t choice;

    flag_check_change_file = 0; // reset input/output file because user switches to reading from the keyboard
    if (flag_check_change_file_from_keyboard == 0)
    {
        change_file(output_file_name);
    }

    system("clear");
    do
    {
        printf("\n***************************************\n");
        printf(">> You choose enter data: KEYBOARD\n");
        printf(">> Your output file name: %s", output_file_name);
        printf("\n=======================================");
        printf("\n----------------OPTION-----------------\n");
        printf("  1. Encode (convert text to morsecode)\n");
        printf("  2. Decode (convert morsecode to text)\n");
        printf("  3. Change output file\n");
        printf("  0. Exit\n");
        printf("\nEnter your choice: ");
        choice = validate_num_input();

        switch (choice)
        {
        case ENCODING:
            int result = encode_keyboard(output_file_name);
            printf("Message: ");
            read_and_print_file(output_file_name);
            break;
        case DECODING:
            decode_keyboard(output_file_name);
            printf("Message: ");
            read_and_print_file(output_file_name);
            printf("\n");
            break;
        case CHANGE_FILE:
            flag_check_change_file_from_keyboard++;
            printf(">> New: ");
            change_file(output_file_name);
            choice = 0;
            break;
        case EXIT:
            printf(">> Exit. Back to main program\n");
            break;
        default:
            printf(">> Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);
}

void main_menu(char *file_name, char *output_file_name)
{
    choice_t choice;
    system("clear");
    do
    {
        printf("\n=======================================");
        printf("\n----------------OPTION-----------------\n");
        printf("      1. Enter data from keyboard\n");
        printf("      2. Read data from file\n");
        printf("      0. Exit\n");
        printf("\nEnter your choice: ");

        choice = validate_num_input();

        switch (choice)
        {
        case KEYBOARD_DATA:
            printf(">> You choose enter data from keyboard\n");
            data_from_keyboard_menu(output_file_name);
            break;
        case READ_FILE:
            printf(">> You choose enter data from FILE\n");
            data_from_file_menu(file_name, output_file_name);
            break;
        case EXIT_PROGRAM:
            printf(">> Exiting program.\n");
            break;
        default:
            printf(">> Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);
}