/* Filename: shell_functions.c */

#include "shell_header.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * custom_logical_operators - Custom function to handle the && and || operators
 * @args: Array of arguments
 * @env: Array of environment variables
 * @status: Exit status
 */
void custom_logical_operators(char **args, char **env, int *status)
{
    pid_t child_pid;
    int child_status;

    while (*args != NULL)
    {
        child_pid = fork();
        if (child_pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (child_pid == 0)
        {
            custom_execute(args, env, status);
            exit(EXIT_SUCCESS);
        }
        else
        {
            waitpid(child_pid, &child_status, 0);
            *status = WEXITSTATUS(child_status);

            if ((*args + 1) != NULL)
            {
                if ((*(args + 1))[0] == '&' && (*(args + 1))[1] == '&')
                {
                    if (*status != 0)
                        break;
                }
                else if ((*(args + 1))[0] == '|' && (*(args + 1))[1] == '|')
                {
                    if (*status == 0)
                        break;
                }
            }

            args++;
        }
    }
}
