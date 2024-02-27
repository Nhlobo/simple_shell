#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ALIAS_SIZE 100

struct Alias {
    char alias_name[MAX_ALIAS_SIZE];
    char alias_command[MAX_INPUT_SIZE];
};

struct Alias alias_list[MAX_ALIAS_SIZE];

void execute_command_with_alias(char *command);
void handle_alias(char *alias_input);
void print_aliases();

int main(void) {
    char input[MAX_INPUT_SIZE];

    while (1) {
        printf("$ ");  // Display prompt
        fgets(input, MAX_INPUT_SIZE, stdin);

        // Remove newline character
        if (input[strlen(input) - 1] == '\n') {
            input[strlen(input) - 1] = '\0';
        }

        if (strcmp(input, "alias") == 0) {
            print_aliases();
        } else if (strncmp(input, "alias ", 6) == 0) {
            handle_alias(input);
        } else {
            execute_command_with_alias(input);
        }
    }

    return 0;
}

void execute_command_with_alias(char *command) {
    // Check if the command is an alias
    for (int i = 0; i < MAX_ALIAS_SIZE; i++) {
        if (strcmp(alias_list[i].alias_name, command) == 0) {
            command = alias_list[i].alias_command;
            break;
        }
    }

    // Execute the command
    system(command);
}

void handle_alias(char *alias_input) {
    char *alias_tokens[MAX_ALIAS_SIZE];
    int alias_token_count = 0;

    // Tokenize alias input
    char *token = strtok(alias_input, " ");
    while (token != NULL && alias_token_count < MAX_ALIAS_SIZE) {
        alias_tokens[alias_token_count++] = token;
        token = strtok(NULL, " ");
    }

    // Validate alias syntax
    if (alias_token_count < 4 || strcmp(alias_tokens[2], "=") != 0) {
        printf("Invalid alias syntax\n");
        return;
    }

    // Extract alias name and command
    char *alias_name = alias_tokens[1];
    char *alias_command = alias_tokens[3];

    // Store alias in the list
    for (int i = 0; i < MAX_ALIAS_SIZE; i++) {
        if (alias_list[i].alias_name[0] == '\0') {
            strncpy(alias_list[i].alias_name, alias_name, MAX_ALIAS_SIZE - 1);
            strncpy(alias_list[i].alias_command, alias_command, MAX_INPUT_SIZE - 1);
            printf("Alias created: %s\n", alias_name);
            return;
        }
    }

    printf("Alias list full. Cannot create more aliases.\n");
}

void print_aliases() {
    for (int i = 0; i < MAX_ALIAS_SIZE; i++) {
        if (alias_list[i].alias_name[0] != '\0') {
            printf("%s: %s\n", alias_list[i].alias_name, alias_list[i].alias_command);
        }
    }
}
