#include "menu.h"

int main()
{
    char file_name[MAX_FILE];
    char output_file_name[MAX_FILE];
    init_tree();
    main_menu(file_name, output_file_name);

    return 0;
}