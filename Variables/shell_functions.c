/* Filename: shell_functions.c */

#include "shell_header.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * custom_variable_replacement - Custom function to handle variable replacement
 * @command: Command to check for variable replacement
 * @status: Exit status
 * @env: Array of environment variables
 */
char *custom_variable_replacement(char *command, int status, char **env)
{
    char *replaced_command = strdup(command);
    char *pid_str;
    char *status_str;

    if (replaced_command == NULL)
    {
        perror("strdup");
        exit(EXIT_FAILURE);
    }

    /* Replace $? with exit status */
    if (strstr(replaced_command, "$?") != NULL)
    {
        asprintf(&status_str, "%d", status);
        if (status_str == NULL)
        {
            perror("asprintf");
            exit(EXIT_FAILURE);
        }

        replaced_command = custom_str_replace(replaced_command, "$?", status_str);
        free(status_str);
    }

    /* Replace $$ with process ID */
    if (strstr(replaced_command, "$$") != NULL)
    {
        asprintf(&pid_str, "%d", getpid());
        if (pid_str == NULL)
        {
            perror("asprintf");
            exit(EXIT_FAILURE);
        }

        replaced_command = custom_str_replace(replaced_command, "$$", pid_str);
        free(pid_str);
    }

    /* Replace $variable with environment variable value */
    if (strchr(replaced_command, '$') != NULL)
    {
        replaced_command = custom_replace_env_variables(replaced_command, env);
    }

    return replaced_command;
}
