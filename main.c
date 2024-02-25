#include "shell.h"
#include <stdio.h>

int main(void) {
    char *cmd;

    while (1) {
        print_prompt();
        cmd = read_line();
        execute(cmd);
        free(cmd);  // Free the allocated memory for the command
    }

    return 0;
}
