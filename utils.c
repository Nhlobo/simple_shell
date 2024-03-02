#include <string.h>

char **parse_input(char *input) {
    // Split input string into arguments based on spaces
    int buffer_size = 64;
    int position = 0;
    char **args = malloc(buffer_size * sizeof(char *));
    char *arg;

    if (!args) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    arg = strtok(input, " \t\n");
    while (arg != NULL) {
        args[position] = arg;
        position++;

        if (position >= buffer_size) {
            buffer_size += 64;
            args = realloc(args, buffer_size * sizeof(char *));
            if (!args) {
                fprintf(stderr, "Memory allocation failed\n");
                exit(EXIT_FAILURE);
            }
        }

        arg = strtok(NULL, " \t\n");
    }
    
    args[position] = NULL; // Null-terminate the argument list
    return args;
}
