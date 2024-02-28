#include <stdio.h>

extern char **environ;

int main(int argc, char **argv, char **env) {
    int i = 0;
    while (env[i] != NULL) {
        printf("%s\n", env[i]);
        i++;
    }
    
    return 0;
}
