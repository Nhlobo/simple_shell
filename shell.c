#include "shell.h"
#include "utils.h"
#include "builtins.h"

void run_shell() {
    char *input;
    char **args;
    int status;

    do {
        display_prompt();
        input = custom_getline();
        args = parse_input(input);
        
        if (args[0] != NULL) {
            if (is_builtin(args)) {
                status = execute_builtin(args);
            } else {
                status = execute_command(args);
            }
        }

        free(input);
        free(args);

    } while (status);
}
