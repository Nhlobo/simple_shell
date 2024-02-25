#include "shell.h"
#include <stdio.h>

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

        // Rest of your main function

        free(cmd);
    }

    return 0;
}
