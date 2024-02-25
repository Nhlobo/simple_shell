#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int execute(char *cmd) {
    pid_t pid, wpid;
    int status;

    pid = fork();
    if (pid == -1) {
        perror("fork");
        _exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        char *args[2] = {cmd, NULL};
        if (execvp(cmd, args) == -1) {
            perror("execvp");
            _exit(EXIT_FAILURE);
        }
        _exit(EXIT_SUCCESS);
    } else {
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 0;
}
