#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid;

    printf("Parent process started (pid=%d)\n", getpid());

    pid = fork();
    if (pid < 0) {
        perror("fork failed");
        exit(1);
    }
    else if (pid == 0) {

        printf("Child process (pid=%d, parent=%d)\n", getpid(), getppid());
        printf("Child is doing some work...\n");
        sleep(2);
        printf("Child terminating.\n");
        exit(0);
    }
    else {
        // Parent process
        printf("Parent is waiting for child...\n");
        wait(NULL);
        printf("Parent resumes after child terminates.\n");
    }

    return 0;
}
