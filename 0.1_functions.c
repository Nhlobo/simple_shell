/* Filename: 0.1_functions.c */

#include "shell_header.h"
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

/**
 * custom_read_function - Custom function to read user input
 *
 * Return: User input as a string or NULL on EOF
 */
char *custom_read_function(void)
{
	size_t bufsize = 0;
	char *line = NULL;

	/* Read user input */
	if (getline(&line, &bufsize, stdin) == -1)
	{
		free(line);  /* Free allocated memory on EOF */
		return NULL;
	}

	return line;
}

/**
 * custom_execute_function - Custom function to execute a command
 * @command: Command to be executed
 */
void custom_execute_function(char *command)
{
	if (command == NULL)
	{
		/* Handle EOF condition */
		write(2, "Exiting shell...\n", 18);
		exit(EXIT_SUCCESS);
	}

	/* Remove the newline character from the end of the command */
	size_t len = strlen(command);
	if (len > 0 && command[len - 1] == '\n')
		command[len - 1] = '\0';

	/* Check if the executable exists and is a regular file */
	struct stat sb;
	if (stat(command, &sb) == -1 || !S_ISREG(sb.st_mode))
	{
		write(2, "Command not found\n", 18);
		return;
	}

	/* Use execve to execute the command */
	if (execve(command, NULL, NULL) == -1)
	{
		perror("Execution error");
		exit(EXIT_FAILURE);
	}
}
