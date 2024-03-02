#include "shell.h"

#define BUFFER_SIZE 1024

void run_shell() {
    char input[BUFFER_SIZE];

    while (1) {
        printf("SimpleShell$ ");
        fgets(input, BUFFER_SIZE, stdin);

        // Remove newline character
        input[strcspn(input, "\n")] = 0;

        // Implement your shell logic here
        // For now, let's just print the input
        printf("You entered: %s\n", input);
    }
}
