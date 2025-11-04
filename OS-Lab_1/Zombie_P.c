#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {  
        printf("Child (pid=%d) terminating. %d\n", getpid(),getppid());
    } else {
        
        printf("Parent (pid=%d) sleeping, not waiting.\n", getpid());
        sleep(10);   
    }
    return 0;
}
