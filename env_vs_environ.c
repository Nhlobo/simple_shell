#include <stdio.h>

extern char **environ;

int main(void) {
    printf("Address of env: %p\n", environ);
    printf("Address of environ: %p\n", environ);
    return 0;
}
