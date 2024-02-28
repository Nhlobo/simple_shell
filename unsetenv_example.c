#include <stdio.h>
#include <stdlib.h>

int _unsetenv(const char *name) {
    return unsetenv(name);
}

int main(void) {
    _setenv("MY_VAR", "Hello, World!", 1);
    printf("MY_VAR: %s\n", getenv("MY_VAR"));
    
    _unsetenv("MY_VAR");
    printf("MY_VAR: %s\n", getenv("MY_VAR"));
    
    return 0;
}
