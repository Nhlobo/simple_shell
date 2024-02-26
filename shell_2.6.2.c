#include "shell.h"

void execute_command(char *line)
{
    pid_t child_pid;
    int status;

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("fork");
        return;
    }

    if (child_pid == 0)
    {
        // Child process
        char *token;
        const char delimiters[] = " ";
        token = strtok(line, delimiters);

        int num_args = 1;
        char *args[MAX_ARGS];
        args[0] = token;

        while ((token = strtok(NULL, delimiters)) != NULL && num_args < MAX_ARGS - 1)
        {
            args[num_args] = token;
            num_args++;
        }

        args[num_args] = NULL;

        if (execvp(args[0], args) == -1)
        {
            perror("execvp");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        // Parent process
        waitpid(child_pid, &status, 0);
    }
}

char *read_line(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    if ((read = getline(&line, &len, stdin)) == -1)
    {
        if (feof(stdin))
        {
            printf("\n");
            exit(EXIT_SUCCESS);
        }
        else
        {
            perror("getline");
            exit(EXIT_FAILURE);
        }
    }

    // Remove newline character
    line[strcspn(line, "\n")] = '\0';

    return line;
}

void handle_exit(int status)
{
    exit(status);
}

void handle_env(void)
{
    extern char **environ;
    for (char **env = environ; *env != NULL; env++)
    {
        printf("%s\n", *env);
    }
}
