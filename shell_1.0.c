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
        char *args[2] = {token, NULL};
        if (execve(token, args, NULL) == -1)
        {
            perror("execve");
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

void handle_exit(void)
{
    exit(EXIT_SUCCESS);
}

void handle_env(void)
{
    extern char **environ;
    for (char **env = environ; *env != NULL; env++)
    {
        printf("%s\n", *env);
    }
}
