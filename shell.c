// shell.c

#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * Handles built-in commands like "exit" and "env".
 * @param cmd The command to be handled.
 */
void handle_builtin(char *cmd) {
    if (strcmp(cmd, "exit") == 0) {
        printf("Exiting shell...\n");
        exit(0);
    } else if (strcmp(cmd, "env") == 0) {
        // Implement handling for "env" command
        char **env = environ;
        while (*env != NULL) {
            printf("%s\n", *env);
            env++;
        }
    } else {
        // Tokenize command line
        int i = 0;
        char *token;
        char *args[10];  // Adjust the size based on your requirements
        token = strtok(cmd, " \t\n");
        while (token != NULL) {
            args[i++] = token;
            token = strtok(NULL, " \t\n");
        }
        args[i] = NULL;  // Null-terminate the arguments array

        // Handle non-built-in commands
        execute_command(args);
    }
}

/**
 * Main function for the shell.
 * @return Returns 0 on successful execution.
 */
int main(void) {
    char *cmd;

    while (1) {
        print_prompt();
        cmd = read_line();

        // Check for end of file condition
        if (!cmd) {
            fprintf(stderr, "\nError reading command. Exiting shell...\n");
            break;
        }

        handle_builtin(cmd);

        // Free allocated memory
        free(cmd);
    }

    return 0;
}
