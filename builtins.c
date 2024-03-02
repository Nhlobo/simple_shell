#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int execute_command(char **args) {
    pid_t pid, wpid;
    int status;
    int file_desc;

    char *path = search_path(args[0]);
    if (!path) {
        fprintf(stderr, "%s: command not found\n", args[0]);
        return 1;
    }

    pid = fork();
    if (pid == 0) {
        // Child process
        if (args[1] && strcmp(args[1], "<") == 0 && args[2]) {
            file_desc = open(args[2], O_RDONLY);
            if (file_desc < 0) {
                perror("shell");
                exit(EXIT_FAILURE);
            }
            dup2(file_desc, STDIN_FILENO);
            close(file_desc);
        }

        if (args[1] && strcmp(args[1], ">") == 0 && args[2]) {
            file_desc = open(args[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (file_desc < 0) {
                perror("shell");
                exit(EXIT_FAILURE);
            }
            dup2(file_desc, STDOUT_FILENO);
            close(file_desc);
        }

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
