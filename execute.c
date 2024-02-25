// execute.c

#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * Executes the given command.
 * @param cmd The command to be executed.
 * @return Returns 0 on successful execution.
 */
int execute(char *cmd) {
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        _exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Prepare arguments for execvp
        char *args[2] = {cmd, NULL};
        
        // Execute the command
        if (execvp(cmd, args) == -1) {
            perror("execvp");
            _exit(EXIT_FAILURE);
        }

        // This code is unreachable after execvp
        _exit(EXIT_SUCCESS);
    } else {
        // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));

        // Check if the command was terminated by a signal
        if (WIFSIGNALED(status)) {
            fprintf(stderr, "Command terminated by signal %d\n", WTERMSIG(status));
        }
    }

    return 0;
}
