#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char *search_path(char *command) {
    char *path = getenv("PATH");
    char *path_copy = strdup(path);
    char *path_token = strtok(path_copy, ":");

    while (path_token) {
        char *full_path = malloc(strlen(path_token) + strlen(command) + 2);
        sprintf(full_path, "%s/%s", path_token, command);
        
        if (access(full_path, X_OK) == 0) { // Check if the path is executable
            free(path_copy);
            return full_path;
        }

        free(full_path);
        path_token = strtok(NULL, ":");
    }

    free(path_copy);
    return NULL;
}
