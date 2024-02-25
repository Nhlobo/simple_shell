#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

char *read_line(void) {
    char *line = NULL;
    size_t len = 0;

    if (getline(&line, &len, stdin) == -1) {
        perror("read_line");
        exit(EXIT_FAILURE);
    }

    return line;
}
