#include <stdio.h>
#include <unistd.h>

int main(void) {
    pid_t child_pid;
    pid_t my_pid;
    
    printf("Before fork\n");
    child_pid = fork();
    
    if (child_pid == -1) {
        perror("Error:");
        return 1;
    }
    
    printf("After fork\n");
    my_pid = getpid();
    printf("My pid is %u\n", my_pid);
    
    return 0;
}
