/* Filename: shell_functions.c */

#include "shell_header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * custom_alias - Custom function to handle the alias command
 * @args: Array of arguments
 * @aliases: Array of alias structures
 */
void custom_alias(char **args, alias_t **aliases)
{
    int i;

    if (args[1] == NULL)
    {
        /* Print all aliases */
        for (i = 0; aliases[i] != NULL; i++)
            printf("%s='%s'\n", aliases[i]->name, aliases[i]->value);
    }
    else
    {
        /* Check if alias already exists */
        for (i = 0; aliases[i] != NULL; i++)
        {
            if (strcmp(aliases[i]->name, args[1]) == 0)
            {
                /* Update alias value */
                free(aliases[i]->value);
                aliases[i]->value = strdup(args[2]);
                return;
            }
        }

        /* Create a new alias */
        *aliases = realloc(*aliases, (i + 2) * sizeof(alias_t));
        if (*aliases == NULL)
        {
            perror("realloc");
            exit(EXIT_FAILURE);
        }

        (*aliases)[i] = malloc(sizeof(alias_t));
        if ((*aliases)[i] == NULL)
        {
            perror("malloc");
            exit(EXIT_FAILURE);
        }

        (*aliases)[i]->name = strdup(args[1]);
        (*aliases)[i]->value = strdup(args[2]);
        (*aliases)[i + 1] = NULL;
    }
}
