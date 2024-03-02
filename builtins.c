#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int execute_command(char **args) {
    pid_t pid, wpid;
    int status;

    char *path = search_path(args[0]);
    if (!path) {
        fprintf(stderr, "%s: command not found\n", args[0]);
        return 1;
    }

    pid = fork();
    if (pid == 0) {
        // Child process
        if (execv(path, args) == -1) {
            perror("shell");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // Error forking
        perror("shell");
    } else {
        // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    free(path);
    return 1;
}
