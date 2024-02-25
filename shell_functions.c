/* Filename: shell_functions.c */

#include "shell_header.h"
#include <stdlib.h>

/**
 * custom_setenv - Custom function to implement the setenv built-in command
 * @args: Array of arguments
 */
void custom_setenv(char **args)
{
    if (args[1] == NULL || args[2] == NULL)
    {
        fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
        return;
    }

    if (setenv(args[1], args[2], 1) == -1)
    {
        perror("Error setting environment variable");
    }
}

/**
 * custom_unsetenv - Custom function to implement the unsetenv built-in command
 * @args: Array of arguments
 */
void custom_unsetenv(char **args)
{
    if (args[1] == NULL)
    {
        fprintf(stderr, "Usage: unsetenv VARIABLE\n");
        return;
    }

    if (unsetenv(args[1]) == -1)
    {
        perror("Error unsetting environment variable");
    }
}
