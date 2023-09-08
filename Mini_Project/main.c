#include "menu.h"

int main()
{
    char file_name[MAX_FILE];
    char output_file_name[MAX_FILE];
    tree_node_t *root = build_morse_code_tree();
    main_menu(file_name, output_file_name, root);

    return 0;
}