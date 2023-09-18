#include "menu.h"

int main()
{
    char file_name[MAX_FILE] = {0};
    char output_file_name[MAX_FILE] = {0};
    init_tree();
    main_menu(file_name, output_file_name);

    return 0;
}