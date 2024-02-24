#include "shell.h"

/**
 * main - Entry point for the shell
 * Return: Always 0
 */
int main(void)
{
	char *cmd;

	while (1)
	{
		print_prompt();
		cmd = read_line();
		if (!cmd)
			break;
		execute(cmd);
		free(cmd);
	}

	return (0);  // Corrected line
}
