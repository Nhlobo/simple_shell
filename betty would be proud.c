#include <stdio.h>
#include <stdlib.h>

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

        // Your logic for handling user input and executing commands goes here

        printf("$ ");
    }

    free(input);
    return 0;
}
