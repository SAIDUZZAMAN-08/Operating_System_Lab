#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <pthread.h>

using namespace std;

struct thread_data
{
    int *arr;
    int start;
    int end;
};

void *partial_sum(void *arg)
{
    int sum = 0;
    thread_data *data = (thread_data *)arg;

    for (int i = data->start; i < data->end; i++)
    {
        sum += data->arr[i];
    }

    int *sum_ptr = new int(sum);
    return (void *)sum_ptr;
}

int main()
{

    int arr[20];
    for (int i = 0; i < 20; i++)
    {
        arr[i] = i + 1;
    }

    thread_data data1, data2;

    data1.arr = arr;
    data1.start = 0;
    data1.end = sizeof(arr) / sizeof(arr[0]) / 2;

    data2.arr = arr;
    data2.start = sizeof(arr) / sizeof(arr[0]) / 2;
    data2.end = sizeof(arr) / sizeof(arr[0]);

    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, partial_sum, (void *)&data1);
    pthread_create(&thread2, NULL, partial_sum, (void *)&data2);

    void *sum1, *sum2;

    pthread_join(thread1,&sum1);
    pthread_join(thread2,&sum2);

    int *s1 = (int *)sum1;
    int *s2 = (int *)sum2;

    cout << "Sum of first half: " << *s1 << endl;
    cout << "Sum of second half: " << *s1 << endl;
    cout << "Total sum: " << *s1 + *s2 << endl;

    

    return 0;
}