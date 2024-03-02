#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 128

void run_shell();
int parse_input(char *input, char **args);
void execute_command(char **args);

#endif
