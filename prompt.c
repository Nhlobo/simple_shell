#include <stdio.h>

int main(void) {
    printf("$ ");
    fflush(stdout);

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, stdin)) != -1) {
        printf("%s", line);
        printf("$ ");
        fflush(stdout);
    }

    free(line);
    return 0;
}
