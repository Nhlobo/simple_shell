#include "shell.h"

#define BUFFER_SIZE 1024

void run_shell() {
    char input[MAX_INPUT_SIZE];
    char *args[MAX_ARGS];
    
    while (1) {
        printf("SimpleShell> ");
        fgets(input, sizeof(input), stdin);
        
        input[strcspn(input, "\n")] = '\0'; // Remove newline character from input
        
        int num_args = parse_input(input, args); // Parse input into arguments
        
        if (num_args > 0) {
            if (strcmp(args[0], "exit") == 0) {
                break; // Exit the shell
            } else {
                execute_command(args); // Execute command
            }
        }
    }
}
