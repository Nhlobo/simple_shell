#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

char *custom_getline() {
    char *input = malloc(BUFFER_SIZE * sizeof(char));
    if (!input) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    if (fgets(input, BUFFER_SIZE, stdin) == NULL) {
        free(input);
        return NULL;
    }

    return input;
}
