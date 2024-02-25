// print_prompt.c

#include "shell.h"
#include <unistd.h>

/**
 * Prints the shell prompt.
 */
void print_prompt(void) {
    write(STDOUT_FILENO, "$ ", 2);
}
