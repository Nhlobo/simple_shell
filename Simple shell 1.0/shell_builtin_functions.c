/* Filename: shell_builtin_functions.c */

#include "shell_header.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * custom_exit_function - Custom function to exit the shell
 * @args: Arguments passed to the exit command
 */
void custom_exit_function(char **args)
{
    (void)args; /* Unused parameter */

    /* Clean up and exit the shell */
    exit(EXIT_SUCCESS);
}

/**
 * custom_env_function - Custom function to print the current environment
 * @args: Arguments passed to the env command
 */
void custom_env_function(char **args)
{
    int i;
    extern char **environ;

    (void)args; /* Unused parameter */

    /* Print the current environment */
    for (i = 0; environ[i] != NULL; i++)
    {
        printf("%s\n", environ[i]);
    }
}
