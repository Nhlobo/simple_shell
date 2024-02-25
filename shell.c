#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void execute_command(char *command) {
    char *path = search_path(command);

    if (path != NULL) {
        printf("Executing command: %s\n", path);
        // Implement code to execute the command using execve
    } else {
        printf("Command not found: %s\n", command);
    }
}

char *search_path(char *command) {
    // Implement code to search for the executable in the directories specified by PATH
    // Return the full path to the executable if found, otherwise return NULL
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
        execute_command(cmd);

        free(cmd);
    }

    return 0;
}
