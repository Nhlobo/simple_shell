#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s path_to_file ...\n", argv[0]);
        return 1;
    }
    
    int i = 1;
    while (argv[i] != NULL) {
        printf("%s:", argv[i]);
        struct stat st;
        if (stat(argv[i], &st) == 0) {
            printf(" FOUND\n");
        } else {
            printf(" NOT FOUND\n");
        }
        i++;
    }
    
    return 0;
}
