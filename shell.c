#include "shell.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void handle_builtin(char *cmd) {
    if (strcmp(cmd, "exit") == 0) {
        printf("Exiting shell...\n");
        exit(0);
    } else if (strcmp(cmd, "env") == 0) {
        // Implement handling for "env" command
        printf("Environment variables:\n");
        // Print environment variables
    } else {
        // Handle non-built-in commands
        execute_command(cmd);
    }
}

int main(void) {
    char *cmd;

    while (1) {
        print_prompt();
        cmd = read_line();

        // Check for end of file condition
        if (!cmd) {
            printf("\nExiting shell...\n");
            break;
        }

        handle_builtin(cmd);

        // Free allocated memory
        free(cmd);
    }

    return 0;
}
