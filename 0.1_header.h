/* Filename: shel_header.h */

#ifndef SHELL_HEADER_H
#define SHELL_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *custom_read_function(void);
void custom_execute_function(char *command);

#endif /* SHELL_HEADER_H */
