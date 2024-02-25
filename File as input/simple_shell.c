/* Filename: simple_shell.c */

#include "shell_header.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *file_path = "path/to/your/file.txt"; /* Change to your actual file path */
    char *env[] = {"VAR1=value1", "VAR2=value2", NULL}; /* Example environment variables */
    int status = 0;

    execute_file_commands(file_path, env, &status);

    return status;
}
