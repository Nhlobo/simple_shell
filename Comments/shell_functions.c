/* Filename: shell_functions.c */

#include "shell_header.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * remove_comments - Remove comments from a command line
 * @command: Command to remove comments from
 */
char *remove_comments(char *command)
{
    char *result;
    char *comment_start;

    comment_start = strchr(command, '#');
    if (comment_start != NULL)
    {
        result = strndup(command, comment_start - command);
        if (result == NULL)
        {
            perror("strndup");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        result = strdup(command);
        if (result == NULL)
        {
            perror("strdup");
            exit(EXIT_FAILURE);
        }
    }

    return result;
}
