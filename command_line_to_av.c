#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **split_string(char *line) {
    char **tokens = malloc(sizeof(char*));
    char *token;
    int token_count = 0;
    
    token = strtok(line, " ");
    while (token != NULL) {
        tokens[token_count] = token;
        token_count++;
        tokens = realloc(tokens, (token_count + 1) * sizeof(char*));
        token = strtok(NULL, " ");
    }
    
    tokens[token_count] = NULL;
    return tokens;
}

int main(void) {
    char line[100];
    fgets(line, sizeof(line), stdin);
    line[strcspn(line, "\n")] = '\0';
    
    char **arguments = split_string(line);
    for (int i = 0; arguments[i] != NULL; i++) {
        printf("%s\n", arguments[i]);
    }
    
    free(arguments);
    return 0;
}
