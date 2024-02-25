#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>

void print_prompt(void);
char *read_line(void);
void execute_command(char *command);
void handle_builtin_commands(char *command);
char *search_path(char *command);
void handle_special_characters(char *command);
void implement_redirections(char *command);
void implement_pipes(char *command);
void implement_cursor_movement(char *command);

#endif /* SHELL_H */
