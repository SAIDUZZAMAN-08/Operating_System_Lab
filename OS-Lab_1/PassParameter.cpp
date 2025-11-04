#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h>   

void *thread_fun(void *arg)
{
    printf("Inside thread\n");
    int *array = (int *)arg;   // cast void* back to int array
    int sum = 0;

    // Loop through array and calculate sum
    for (int i = 0; i < 3; i++) {
        sum += array[i];
        printf("Element %d has been summed. Current sum: %d\n", i, sum);
        sleep(1); 
    }

    printf("Final sum is: %d\n", sum);

    // Return sum safely using intptr_t
    // pthread_exit((void *)(intptr_t)sum);

    int *result=(int*)malloc(sizeof(int));
    *result=sum;
    return (void*)result;
}

int main()
{
    pthread_t thread1;
    int ara[3] = {1, 2, 3};

    pthread_create(&thread1, NULL, thread_fun, &ara);

    void *sum_p;
    // Wait for the thread to finish and collect its return value
    pthread_join(thread1, &sum_p);

    printf("Back to main process\n");

    // Convert the void* back to int
    // int sum = (int)(intptr_t)sum_p;

    int*sum=(int*)sum_p;
    printf("Sum of elements: %d\n", *sum);

    return 0;
}
