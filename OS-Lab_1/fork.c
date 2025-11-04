#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t p1, p2;

    printf("Original Parent P: pid = %d\n", getpid());

    p1 = fork();   // create p1

    if (p1 < 0) {
        printf("Error creating p1\n");
    }
    else if (p1 == 0) {
        // Inside child p1
        printf("Child P1: pid = %d, parent = %d\n", getpid(), getppid());

        p2 = fork();  // create p2 inside p1

        if (p2 < 0) {
            printf("Error creating p2\n");
        }
        else if (p2 == 0) {
            // Inside grandchild p2
            printf("Grandchild P2: pid = %d, parent = %d\n", getpid(), getppid());
        }
        else {
            wait(NULL); // p1 waits for p2
        }
    }
    else {
        wait(NULL); // p waits for p1
    }

    return 0;
}
