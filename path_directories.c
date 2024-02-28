#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_path_directories() {
    char *path = getenv("PATH");
    if (path == NULL) {
        printf("PATH variable not found\n");
        return;
    }
    
    char *token = strtok(path, ":");
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, ":");
    }
}

int main(void) {
    print_path_directories();
    return 0;
}
