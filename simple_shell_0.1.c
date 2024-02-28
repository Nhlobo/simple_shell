#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

/**
 * main - Simple Shell
 *
 * Return: Always 0
 */
int main(void)
{
    char *input = NULL;
    size_t len = 0;

    while (1)
    {
        printf("$ ");
        if (getline(&input, &len, stdin) == -1)
            break;

        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        // Fork a child process
        pid_t pid = fork();

        if (pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0)
        {
            // Child process
            execlp(input, input, NULL);
            perror("execlp");
            exit(EXIT_FAILURE);
        }
        else
        {
            // Parent process
            wait(NULL);
        }
    }

    free(input);
    return 0;
}
