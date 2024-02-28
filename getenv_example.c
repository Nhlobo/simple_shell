#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *_getenv(const char *name) {
    extern char **environ;
    int i = 0;
    while (environ[i] != NULL) {
        char *variable = strtok(environ[i], "=");
        if (strcmp(variable, name) == 0) {
            return strtok(NULL, "=");
        }
        i++;
    }
    return NULL;
}

int main(void) {
    char *home = _getenv("HOME");
    if (home != NULL) {
        printf("HOME: %s\n", home);
    } else {
        printf("HOME variable not found\n");
    }
    return 0;
}
