#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void handle_input_redirection(char *file) {
    int fd = open(file, O_RDONLY);
    if (fd < 0) {
        perror("Input Redirection");
        exit(EXIT_FAILURE);
    }
    dup2(fd, STDIN_FILENO);
    close(fd);
}

void handle_output_redirection(char *file) {
    int fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("Output Redirection");
        exit(EXIT_FAILURE);
    }
    dup2(fd, STDOUT_FILENO);
    close(fd);
}
