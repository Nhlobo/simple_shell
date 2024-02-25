#include "shell.h"
#include <stdio.h>

int main(void) {
    char *cmd;

    while (1) {
        print_prompt();
        cmd = read_line();
        // Execute the command (to be implemented later)
    }

    return 0;
}
