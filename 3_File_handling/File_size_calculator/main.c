#include "file.h"

int main()
{
    char file_name[MAX_FILE_NAME] = {0};
    input_file(file_name);

    long file_size = get_file_size(file_name);
    output_size_file(file_name, file_size);

    return 0;
}