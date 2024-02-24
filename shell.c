#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *cmd = "ls";
    print_prompt();
    execute(cmd);

    return 0;
}
