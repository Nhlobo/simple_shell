#include "shell.h"

/**
 * Main function for the simple shell.
 *
 * It initializes the shell and enters a loop to read and execute commands until the user exits.
 * The `winning_team` function is called before and after executing each command.
 *
 * @return 0 on successful execution.
 */
int main(void) {
    char command[100];
    winning_team();

    while (fgets(command, sizeof(command), stdin) != NULL) {
        execute_command(command);
        winning_team();
    }

    return 0;
}
