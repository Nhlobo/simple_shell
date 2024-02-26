#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    char *command = NULL;
    size_t len = 0;
    ssize_t read_len;

    write(1, "$ ", 2);
    while ((read_len = getline(&command, &len, stdin)) != -1)
    {
        if (read_len > 1) /* Check if not just Enter */
        {
            if (command[read_len - 1] == '\n')
                command[read_len - 1] = '\0';
            custom_execute_function(command);
        }
        write(1, "$ ", 2);
    }

    free(command);
    return (0);
}
