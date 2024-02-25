/* Filename: shell_header.h */

#ifndef SHELL_HEADER_H
#define SHELL_HEADER_H

#include <stddef.h>

/* Function declarations */
char *remove_comments(char *command);
void execute_file_commands(char *file_path, char **env, int *status);
void execute_command(char *command, char **env, int *status);

#endif /* SHELL_HEADER_H */
