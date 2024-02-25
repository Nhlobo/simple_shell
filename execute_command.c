#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * Executes the given command with arguments.
 * @param args The command and its arguments.
 */
void execute_command(char **args) {
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        _exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) {
            // If execvp fails, try to find the command in PATH
            char *path = getenv("PATH");
            char *token = strtok(path, ":");
            while (token != NULL) {
                char full_path[256];  // Adjust the size based on your requirements
                snprintf(full_path, sizeof(full_path), "%s/%s", token, args[0]);

                if (access(full_path, X_OK) == 0) {
                    // Command found in PATH, execute it
                    execv(full_path, args);
                }

                token = strtok(NULL, ":");
            }

            // Command not found
            perror(args[0]);
            _exit(EXIT_FAILURE);
        }
        _exit(EXIT_SUCCESS);
    } else {
        // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));

        if (WIFSIGNALED(status)) {
            fprintf(stderr, "Command terminated by signal %d\n", WTERMSIG(status));
        }
    }
}
