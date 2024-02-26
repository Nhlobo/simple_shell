/* Filename: 0.1.c */

#include "shell_header.h"

/**
 * main - Entry point for the simple shell
 *
 * Return: Always 0
 */
int main(void)
{
    char *command;

    while (1)
    {
        /* Display prompt */
        write(1, "$ ", 2);

        /* Read user input */
        command = custom_read_function();

        /* Execute the command */
        custom_execute_function(command);

        /* Free allocated memory, handle cleanup, etc. */
        free(command);
    }

    return (0);
}
