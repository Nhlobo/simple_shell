#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

int execute_command(char **args) {
    pid_t pid, wpid;
    int status;
    int pipefd[2];

    char *path = search_path(args[0]);
    if (!path) {
        fprintf(stderr, "%s: command not found\n", args[0]);
        return 1;
    }

    if (pipe(pipefd) == -1) {
        perror("shell");
        return 1;
    }

    pid = fork();
    if (pid == 0) {
        // Child process
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[0]);
        close(pipefd[1]);
        
        if (execv(path, args) == -1) {
            perror("shell");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // Error forking
        perror("shell");
        return 1;
    }

    // Parent process
    pid = fork();
    if (pid == 0) {
        // Child process
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[1]);
        close(pipefd[0]);
        
        char **next_args = args + 2;
        char *next_path = search_path(next_args[0]);
        if (!next_path) {
            fprintf(stderr, "%s: command not found\n", next_args[0]);
            return 1;
        }
        
        if (execv(next_path, next_args) == -1) {
            perror("shell");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // Error forking
        perror("shell");
        return 1;
    }

    // Close pipe in parent process
    close(pipefd[0]);
    close(pipefd[1]);

    // Wait for child processes
    do {
        wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));

    free(path);
    return 1;
}
