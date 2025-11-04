#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *thread_function(void *arg)
{
    printf("Hello from thread! Thread ID: %lu\n", (unsigned long)pthread_self());
    fflush(stdout);  // flush immediately

    for(int i = 0; i < 5; i++){
        printf("%d \n", i);
        fflush(stdout);  // flush after each print
        sleep(1);
    }
    return NULL;
}

int main()
{
    pthread_t thread1;

    pthread_create(&thread1, NULL, thread_function, NULL);
    pthread_join(thread1, NULL);

    printf("Back to main process \n");
    fflush(stdout);

    for(int i = 20; i < 25; i++){
        printf("%d \n", i);
        fflush(stdout);
    }

    return 0;
}
