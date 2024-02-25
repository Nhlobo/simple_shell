#include "shell.h"
#include <stdio.h>
#include <string.h>

void handle_builtin_commands(char *command) {
    if (strcmp(command, "exit") == 0) {
        printf("Exiting shell...\n");
        exit(0);
    } else if (strcmp(command, "env") == 0) {
        // Implement env command to print the current environment
        // For example: printf("PATH=%s\n", getenv("PATH"));
    } else {
        // Handle other built-in commands if needed
    }
}

int main(void) {
    char *cmd;

    while (1) {
        print_prompt();
        cmd = read_line();

        if (cmd == NULL) {
            // End of file condition (Ctrl+D)
            printf("\n");
            break;
        }

        handle_builtin_commands(cmd);
        // Execute the command if it's not a built-in command

        free(cmd);
    }

    return 0;
}
