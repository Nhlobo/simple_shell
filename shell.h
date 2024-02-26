#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *read_line(void);
void execute_command(char *line);

#endif /* SHELL_H */
