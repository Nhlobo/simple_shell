#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARGUMENTS 100

void execute_command(char *command);
void handle_path(char *command);
void handle_exit();
void handle_env();
void handle_cd(char *path);
void handle_commands_separator(char *command);
void handle_logical_operators(char *command);
void handle_alias(char *alias_input);
void handle_variables(char *command);
void replace_variables(char *command);
void handle_comments(char *command);
void execute_from_file(char *filename);

int main(void) {
    char input[MAX_INPUT_SIZE];

    while (1) {
        printf("$ ");  // Display prompt
        fgets(input, MAX_INPUT_SIZE, stdin);

        // Remove newline character
        if (input[strlen(input) - 1] == '\n') {
            input[strlen(input) - 1] = '\0';
        }

        if (strcmp(input, "exit") == 0) {
            handle_exit();
        } else if (strcmp(input, "env") == 0) {
            handle_env();
        } else if (strncmp(input, "cd ", 3) == 0) {
            handle_cd(input + 3);
        } else if (strncmp(input, "source ", 7) == 0) {
            execute_from_file(input + 7);
        } else {
            handle_comments(input);
            handle_variables(input);
            replace_variables(input);
            handle_commands_separator(input);
            handle_logical_operators(input);
            execute_command(input);
        }
    }

    return 0;
}

void execute_command(char *command) {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        handle_path(command);
    } else if (pid > 0) {
        // Parent process
        wait(NULL);
    } else {
        // Fork failed
        perror("Fork failed");
    }
}

void handle_path(char *command) {
    char *arguments[MAX_ARGUMENTS];
    int argument_count = 0;

    // Tokenize the command
    char *token = strtok(command, " ");
    while (token != NULL && argument_count < MAX_ARGUMENTS) {
        arguments[argument_count++] = token;
        token = strtok(NULL, " ");
    }

    arguments[argument_count] = NULL;

    // Execute the command
    execvp(arguments[0], arguments);

    // If execvp fails
    perror("Error");
    exit(EXIT_FAILURE);
}

void handle_exit() {
    printf("Exiting shell.\n");
    exit(EXIT_SUCCESS);
}

void handle_env() {
    // Print the current environment
    extern char **environ;
    for (char **env = environ; *env != NULL; env++) {
        printf("%s\n", *env);
    }
}

void handle_cd(char *path) {
    // Change the current directory
    if (chdir(path) != 0) {
        perror("cd failed");
    }
}

void handle_commands_separator(char *command) {
    // Handle commands separated by ';'
    char *separator = strtok(command, ";");
    while (separator != NULL) {
        execute_command(separator);
        separator = strtok(NULL, ";");
    }
}

void handle_logical_operators(char *command) {
    // Handle logical operators '&&' and '||'
    char *and_operator = strstr(command, "&&");
    char *or_operator = strstr(command, "||");

    if (and_operator != NULL) {
        *and_operator = '\0';
        if (system(command) == 0) {
            execute_command(and_operator + 2);
        }
    } else if (or_operator != NULL) {
        *or_operator = '\0';
        if (system(command) != 0) {
            execute_command(or_operator + 2);
        }
    } else {
        system(command);
    }
}

void handle_alias(char *alias_input) {
    // Implementation of the alias command from previous code
}

void handle_variables(char *command) {
    // Implementation of the variables handling from previous code
}

void replace_variables(char *command) {
    // Implementation of the variable replacement from previous code
}

void handle_comments(char *command) {
    // Implementation of comment handling from previous code
}

void execute_from_file(char *filename) {
    // Execute commands from a file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char line[MAX_INPUT_SIZE];
    while (fgets(line, MAX_INPUT_SIZE, file) != NULL) {
        // Remove newline character
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        handle_comments(line);
        handle_variables(line);
        replace_variables(line);
        handle_commands_separator(line);
        handle_logical_operators(line);
        execute_command(line);
    }

    fclose(file);
}
