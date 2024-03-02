#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HISTORY_SIZE 50
char *history[MAX_HISTORY_SIZE];
int history_count = 0;

void add_to_history(char *command) {
    if (history_count < MAX_HISTORY_SIZE) {
        history[history_count] = strdup(command);
        history_count++;
    } else {
        free(history[0]);
        for (int i = 0; i < (MAX_HISTORY_SIZE - 1); i++) {
            history[i] = history[i + 1];
        }
        history[MAX_HISTORY_SIZE - 1] = strdup(command);
    }
}

void display_history() {
    for (int i = 0; i < history_count; i++) {
        printf("%d. %s\n", i+1, history[i]);
    }
}
