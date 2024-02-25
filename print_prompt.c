#include "shell.h"
#include <unistd.h>

void print_prompt(void) {
    write(STDOUT_FILENO, "$ ", 2);
}
