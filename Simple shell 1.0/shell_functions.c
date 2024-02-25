/* Filename: shell_functions.c */

#include "shell_header.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * custom_execute_function - Custom function to execute a command
 * @command: Command to be executed
 * @path_tokens: Array of directory tokens in the PATH
 */
void custom_execute_function(char *command, char **path_tokens)
{
    pid_t child_pid;
    int status;
    char *full_path = NULL;

    if (custom_strcmp(command, "exit") == 0)
    {
        custom_exit_function(NULL);
    }
    else if (custom_strcmp(command, "env") == 0)
    {
        custom_env_function(NULL);
    }

    /* Fork a child process */
    child_pid = fork();

    if (child_pid == -1)
    {
        perror("Error forking");
        return;
    }

    if (child_pid == 0)
    {
        /* Child process */
        full_path = custom_search_path(command, path_tokens);

        if (full_path == NULL)
        {
            fprintf(stderr, "./shell: %s: command not found\n", command);
            free(path_tokens);
            _exit(127);
        }

        execve(full_path, NULL, NULL);
        perror("Error executing command");
        free(full_path);
        free(path_tokens);
        _exit(126);
    }
    else
    {
        /* Parent process */
        waitpid(child_pid, &status, 0);
    }
}
