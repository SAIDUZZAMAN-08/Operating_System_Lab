#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    pid_t p;
    p=fork();

    if(p<0){
        printf("Error");
    }

    else if(p==0){
        sleep(2);
        printf("Child (pid=%d) now orphan, new parent pid=%d\n", getpid(), getppid());
    }

    else {
        printf("Parent (pid=%d) terminating early.\n", getpid());
    }
    
    return 0;

}