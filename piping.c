#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void execute_pipe(char *args1[], char *args2[]) {
    int pipefd[2];
    pid_t pid1, pid2;
    
    if (pipe(pipefd) == -1) {
        perror("Pipe");
        exit(EXIT_FAILURE);
    }
    
    pid1 = fork();
    if (pid1 == 0) {
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[0]);
        execvp(args1[0], args1);
        perror("Execvp");
        exit(EXIT_FAILURE);
    } else if (pid1 > 0) {
        pid2 = fork();
        if (pid2 == 0) {
            dup2(pipefd[0], STDIN_FILENO);
            close(pipefd[1]);
            execvp(args2[0], args2);
            perror("Execvp");
            exit(EXIT_FAILURE);
        } else if (pid2 > 0) {
            close(pipefd[0]);
            close(pipefd[1]);
            waitpid(pid1, NULL, 0);
            waitpid(pid2, NULL, 0);
        } else {
            perror("Fork");
            exit(EXIT_FAILURE);
        }
    } else {
        perror("Fork");
        exit(EXIT_FAILURE);
    }
}
