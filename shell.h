#ifndef SHELL_H
#define SHELL_H

/* Function declarations */
void print_prompt();
char **split_line(char *line);
int execute_command(char **args);
void free_args(char **args);

#endif /* SHELL_H */
