#include <stdio.h>
#include <unistd.h>

void custom_execute_function(char *command)
{
    char *args[10];
    args[0] = command;
    args[1] = NULL;

    if (execve(command, args, NULL) == -1)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }
}
