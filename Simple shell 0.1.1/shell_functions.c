/* Filename: shell_functions.c */

#include "shell_header.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * custom_getline - Custom function to read a line from standard input
 * @buffer: Buffer to store the line
 * @size: Size of the buffer
 * Return: Number of characters read, -1 on failure
 */
ssize_t custom_getline(char **buffer, size_t *size)
{
    ssize_t nread;

    if (*buffer == NULL || *size == 0)
    {
        *size = BUFFER_SIZE;
        *buffer = malloc(*size);
        if (*buffer == NULL)
        {
            perror("Error allocating buffer");
            exit(EXIT_FAILURE);
        }
    }

    nread = read(STDIN_FILENO, *buffer, *size);

    if (nread == -1)
    {
        perror("Error reading input");
        free(*buffer);
        exit(EXIT_FAILURE);
    }

    return nread;
}
