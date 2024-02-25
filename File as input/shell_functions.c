/* Filename: shell_functions.c */

#include "shell_header.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

void execute_file_commands(char *file_path, char **env, int *status)
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    file = fopen(file_path, "r");
    if (file == NULL)
    {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, file)) != -1)
    {
        char *command;

        if (read > 0 && line[read - 1] == '\n')
            line[read - 1] = '\0';

        command = remove_comments(line);

        if (strlen(command) > 0)
        {
            execute_command(command, env, status);
        }

        free(command);
    }

    free(line);
    fclose(file);
}
