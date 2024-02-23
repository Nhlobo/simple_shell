#include "shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

void execute_command(char *command) {
    char *args[4]; // Example: maximum of 3 arguments and one for NULL
    
    // Tokenize the command
    char *token = strtok(command, " ");
    int i = 0;
    while (token != NULL && i < 3) {
        args[i] = token;
        token = strtok(NULL, " ");
        i++;
    }
    args[i] = NULL; // Null-terminate the arguments array

    if (strcmp(args[0], "listdir") == 0) {
        // Execute 'ls' command to list directory
        execvp("ls", args);
    }
    else if (strcmp(args[0], "nav") == 0) {
        // Change directory using 'chdir' system call
        if (args[1] != NULL) {
            chdir(args[1]);
        }
    }
    else if (strcmp(args[0], "showdir") == 0) {
        // Display current working directory using 'getcwd' system call
        char cwd[1024];
        getcwd(cwd, sizeof(cwd));
        printf("Current directory: %s\n", cwd);
    }
    else if (strcmp(args[0], "createdir") == 0) {
        // Create a new directory using 'mkdir' system call
        if (args[1] != NULL) {
            mkdir(args[1], 0777);
        }
    }
    else if (strcmp(args[0], "erase") == 0) {
        // Remove a file or directory using 'remove' or 'rmdir' system call
        if (args[1] != NULL) {
            struct stat path_stat;
            stat(args[1], &path_stat);
            if (S_ISREG(path_stat.st_mode)) {
                remove(args[1]);
            }
            else if (S_ISDIR(path_stat.st_mode)) {
                rmdir(args[1]);
            }
        }
    }
    else if (strcmp(args[0], "read") == 0) {
        // Read and display the contents of a file using 'cat' command
        if (args[1] != NULL) {
            args[0] = "cat";
            args[1] = NULL; // Null-terminate the arguments array
            execvp("cat", args);
        }
    }
    // Add more command implementations for the remaining commands
    else {
        printf("Invalid command\n");
    }
}
