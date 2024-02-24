#include "shell.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

/**
 * Execute a shell command.
 *
 * This function takes a command string, tokenizes it, and performs the corresponding action
 * based on the command. It supports commands like listing directories, changing directories, 
 * displaying the current working directory, creating directories, erasing files/directories, 
 * and reading file contents.
 *
 * @param command The command string to be executed.
 */
void execute_command(char *command) {
    char *args[4]; /* Example: maximum of 3 arguments and one for NULL */
    
    // Tokenize the command
    char *token = strtok(command, " ");
    int i = 0;
    while (token != NULL && i < 3) {
        args[i] = token;
        token = strtok(NULL, " ");
        i++;
    }
    args[i] = NULL; // Null-terminate the arguments array

    // Rest of the function remains unchanged...
}
