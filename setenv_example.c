#include <stdio.h>
#include <stdlib.h>

int _setenv(const char *name, const char *value, int overwrite) {
    if (getenv(name) == NULL || overwrite) {
        char *env_variable = malloc(strlen(name) + strlen(value) + 2);
        sprintf(env_variable, "%s=%s", name, value);
        return putenv(env_variable);
    }
    return 0;
}

int main(void) {
    _setenv("MY_VAR", "Hello, World!", 1);
    printf("MY_VAR: %s\n", getenv("MY_VAR"));
    return 0;
}
