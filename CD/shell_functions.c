/* Filename: shell_functions.c */

#include "shell_header.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * custom_cd - Custom function to implement the cd built-in command
 * @args: Array of arguments
 * @env: Array of environment variables
 */
void custom_cd(char **args, char **env)
{
    char *home_dir = NULL;
    char *target_dir = args[1];

    if (target_dir == NULL || *target_dir == '~')
    {
        home_dir = custom_get_env("HOME", env);
        if (home_dir == NULL)
        {
            fprintf(stderr, "cd: No HOME directory in environment\n");
            return;
        }
        target_dir = home_dir;
    }

    if (chdir(target_dir) == -1)
    {
        perror("chdir");
    }

    custom_set_env("OLDPWD", custom_get_env("PWD", env), env);
    custom_set_env("PWD", custom_getcwd(), env);
}
