#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *input = NULL;
    size_t len = 0;

    while (1) {
        printf("SimpleShell$ ");
        if (getline(&input, &len, stdin) == -1)
            break;

        // Your logic for handling user input and executing commands goes here

        printf("SimpleShell$ ");
    }

    free(input);
    return 0;
}
