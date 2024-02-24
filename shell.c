#include "shell.h"

/**
 * main - Entry point for the shell
 * @argc: Number of arguments
 * @argv: Array of argument strings
 * @envp: Array of environment variable strings
 * Return: 0 on success, otherwise an error code
 */
int main(int argc, char *argv[], char *envp[])
{
    (void)argc;
    (void)argv;
    (void)envp;

    while (1)
    {
        char *line;
        char **args;
        int status;

        print_prompt(); /* Your existing code to print the prompt */

        line = read_line(); /* Your existing code to read a line from user input */
        args = split_line(line); /* Your existing code to split the line into arguments */

        status = execute(args, envp); /* Your existing code to execute the command */

        free(line); /* Your existing code to free allocated memory */
        free(args); /* Your existing code to free allocated memory */

        if (status == 0)
            break; /* Break the loop if the user enters "exit" or a similar exit condition */
    }

    return (0);
}

/**
 * print_prompt - Print the shell prompt
 */
void print_prompt(void)
{
    write(STDOUT_FILENO, "$ ", 2);
}

/* Your existing code for read_line, split_line, and execute functions goes here */
