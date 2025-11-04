#include <stdio.h>
#include <pthread.h>

typedef struct {
    int *arr;
    int start;
    int end;
    int sum;
} ThreadData;

void *partial_sum(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    data->sum = 0;
    for (int i = data->start; i < data->end; i++) {
        data->sum += data->arr[i];
    }
    return NULL;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    pthread_t t1, t2;
    ThreadData d1 = {arr, 0, n/2, 0};
    ThreadData d2 = {arr, n/2, n, 0};

    pthread_create(&t1, NULL, partial_sum, &d1);
    pthread_create(&t2, NULL, partial_sum, &d2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Partial sum 1 = %d\n", d1.sum);
    printf("Partial sum 2 = %d\n", d2.sum);
    int s=d1.sum+d2.sum;

    printf("Total Sum: %d\n",s);
    
    return 0;
}
