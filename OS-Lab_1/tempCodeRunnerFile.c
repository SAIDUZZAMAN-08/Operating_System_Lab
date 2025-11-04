#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child
        printf("Child (pid=%d) is running.\n", getpid());
        sleep(2);
        printf("Child terminating.\n");
    } else {
        // Parent
        printf("Parent (pid=%d) waiting for child...\n", getpid());
        wait(NULL);
        printf("Parent resumes after child terminates.\n");
    }

    return 0;
}
