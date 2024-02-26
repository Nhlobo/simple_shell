#include "shell.h"

int main(void)
{
    char *line;

    do {
        printf("#cisfun$ ");
        line = read_line();
        if (line)
        {
            execute_command(line);
            free(line);
        }
    } while (1);

    return 0;
}
