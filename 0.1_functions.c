#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 * custom_execute_function - Function to execute custom commands
 * @command: Command to be executed
 */
void custom_execute_function(char *command)
{
    pid_t child_pid;
    int status;

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0)
    {
        /* Child process */
        if (execve(command, NULL, NULL) == -1)
        {
            perror("Error");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        /* Parent process */
        waitpid(child_pid, &status, 0);
    }
}
