#include <iostream>
#include <pthread.h>
#include <algorithm>  
using namespace std;

struct ArrayData {
    int *arr;
    int size;
};

void *sort_array(void *arg) {
    ArrayData *data = (ArrayData *)arg;
    sort(data->arr, data->arr + data->size);  
    return nullptr;
}

int main() {
    int arr[] = {5, 2, 9, 1, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    ArrayData data = {arr, n};
    pthread_t tid;

    pthread_create(&tid, nullptr, sort_array, &data);
    pthread_join(tid, nullptr);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
