/* Filename: shell_functions.c */

#include "shell_header.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * custom_strtok - Custom function to tokenize a string
 * @str: String to be tokenized
 * @delimiter: Delimiter character
 * Return: Array of tokens
 */
char **custom_strtok(char *str, const char *delimiter)
{
    char **tokens = NULL;
    char *token;
    size_t i = 0;
    size_t token_count = 0;

    tokens = malloc(sizeof(char *) * (token_count + 1));
    if (tokens == NULL)
    {
        perror("Error allocating tokens array");
        exit(EXIT_FAILURE);
    }

    token = strtok(str, delimiter);

    while (token != NULL)
    {
        tokens[i] = token;
        i++;
        token_count++;

        tokens = realloc(tokens, sizeof(char *) * (token_count + 1));
        if (tokens == NULL)
        {
            perror("Error reallocating tokens array");
            exit(EXIT_FAILURE);
        }

        token = strtok(NULL, delimiter);
    }

    tokens[i] = NULL;

    return tokens;
}
