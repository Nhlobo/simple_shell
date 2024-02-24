#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * execute - Execute a command in the shell
 * @cmd: The command to be executed
 * Return: Always 0 (success)
 */
int execute(char *cmd)
{
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        _exit(EXIT_FAILURE);  // Use _exit instead of exit in child process
    }

    if (pid == 0)
    {
        char *args[2] = {cmd, NULL};
        if (execve(cmd, args, NULL) == -1)
        {
            perror("execve");
            _exit(EXIT_FAILURE);  // Use _exit in case of execve failure
        }
        _exit(EXIT_SUCCESS);
    }
    else
    {
        do
        {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 0;
}
