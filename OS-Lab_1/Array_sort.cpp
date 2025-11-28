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

//start

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




#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>

using namespace std;

// Function to sort a portion of the array
void sortPart(vector<int>& arr, int start, int end) {
    sort(arr.begin() + start, arr.begin() + end);
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 6, 3, 8, 4};
    int n = arr.size();

    // Split array into two halves
    int mid = n / 2;

    // Create two threads to sort each half
    thread t1(sortPart, ref(arr), 0, mid);
    thread t2(sortPart, ref(arr), mid, n);

    // Wait for threads to finish
    t1.join();
    t2.join();

    // Merge the two sorted halves
    vector<int> sortedArr(n);
    merge(arr.begin(), arr.begin() + mid, arr.begin() + mid, arr.end(), sortedArr.begin());

    // Print sorted array
    cout << "Sorted array: ";
    for (int num : sortedArr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

