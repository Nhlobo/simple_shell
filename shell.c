#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 128

int parse_input(char *input, char **args) {
    int num_args = 0;
    char *token = strtok(input, " ");
    
    while (token != NULL && num_args < MAX_ARGS) {
        args[num_args] = token;
        num_args++;
        token = strtok(NULL, " ");
    }
    
    args[num_args] = NULL;
    
    return num_args;
}

void execute_command(char **args) {
    pid_t pid = fork();
    
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("Error");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("Error");
    } else {
        wait(NULL);
    }
}

void run_shell() {
    char input[MAX_INPUT_SIZE];
    char *args[MAX_ARGS];
    
    while (1) {
        printf("SimpleShell> ");
        fgets(input, sizeof(input), stdin);
        
        input[strcspn(input, "\n")] = '\0'; 
        
        int num_args = parse_input(input, args);
        
        if (num_args > 0) {
            if (strcmp(args[0], "exit") == 0) {
                break;
            } else {
                execute_command(args);
            }
        }
    }
}

int main() {
    run_shell();
    
    return 0;
}
