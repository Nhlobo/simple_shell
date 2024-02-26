#include "shell.h"

char *read_line(void)
{
    size_t bufsize = 0;
    char *line = NULL;

    if (getline(&line, &bufsize, stdin) == EOF)
    {
        free(line);
        printf("\n");
        exit(EXIT_SUCCESS);
    }

    return line;
}
