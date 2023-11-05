#include "shell.h"

int main(void) {
    char command[100];
    winning_team();

    while (fgets(command, sizeof(command), stdin) != NULL) {
        execute_command(command);
        winning_team();
    }

    return 0;
}
