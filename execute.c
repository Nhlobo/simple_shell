#include "shell.h"

/**
 * execute - Execute a command in the shell
 * @cmd: The command to be executed
 * Return: Always 0 (success)
 */
int execute(char *cmd)
{
	if (fork() == 0)
	{
		char *args[2] = {cmd, NULL};

		if (execve(cmd, args, NULL) == -1)
		{
			perror("Error");
		}
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}

	return 0;
}
