#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void handle_cd(char *args[]) {
    if (args[1] == NULL) {
        fprintf(stderr, "cd: missing argument\n");
    } else {
        if (chdir(args[1]) != 0) {
            perror("cd");
        }
    }
}

void handle_help() {
    printf("Simple Shell Help:\n");
    printf("1. cd [directory] - Change current directory\n");
    printf("2. exit - Exit the shell\n");
}
