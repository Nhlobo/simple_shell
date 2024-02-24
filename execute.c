#include "shell.h"

/**
 * execute - Execute a command
 * @args: The arguments including the command itself
 * @env: The environment variables
 * Return: 0 on success, otherwise an error code
 */
int execute(char **args, char **env)
{
	if (args == NULL || args[0] == NULL)
		return (0);

	if (_strcmp(args[0], "env") == 0)
	{
		/* Check for "env" command */
		char **env_copy = copy_env(env);

		/* Your code to handle the case goes here */
		int i = 0;
		while (env_copy[i] != NULL)
		{
			char *current_var = env_copy[i];
			if (strncmp(current_var, "VARIABLE_TO_KEEP=", 17) != 0)
			{
				/* If not the variable to keep, remove it */
				free(env_copy[i]);
				env_copy[i] = NULL;
			}
			i++;
		}

		/* Execute the command */
		int status = launch(args, env_copy);

		/* Free the copy of environment variables */
		free_env(env_copy);
		return (status);
	}

	/* Your existing code for other commands goes here */

	return (1); /* Indicate command not found */
}
