/* Filename: shell_functions.c */

#include "shell_header.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * custom_exit - Custom function to implement the exit built-in command
 * @status: Exit status
 */
void custom_exit(int status)
{
    if (status != 0)
        fprintf(stderr, "exit %d\n", status);

    exit(status);
}
