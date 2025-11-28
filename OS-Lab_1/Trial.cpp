// #include<stdio.h>
// #include <iostream>
// #include<unistd.h>
// #include<pthread.h>

// using namespace std;

// struct thread_data
// {
//     int *array;
//     int start;
//     int end;
// };

// void *partial_sum(void *arg) {
//     int sum=0;
//     thread_data *data = (thread_data *)arg;
//     for(int i=data->start;i<data->end;i++)
//     {
//         sum+=data->array[i];
//     }
//     int *sum_ptr = new int(sum);
//     return (void *)sum_ptr;
// }


// int main()
// {
//     int array[20];
	
//     for(int i=0;i<20;i++)
//     {
//         array[i]=i+1;
//     }

// 	int n = sizeof(array)/sizeof(array[0]);

//     thread_data data1, data2;
//     // data1.array = array;
//     // data1.start = 0;
//     // data1.end = sizeof(array)/sizeof(array[0])/2;

// 	data1={array,0,n/2};

//     // data2.array = array;
//     // data2.start = sizeof(array)/sizeof(array[0])/2;
//     // data2.end = sizeof(array)/sizeof(array[0]);

// 	data2={array,n/2,n};

//     pthread_t thread1, thread2;

//     pthread_create(&thread1, NULL, partial_sum, (void *)&data1);

//     pthread_create(&thread2, NULL, partial_sum, (void *)&data2);

//     void* sum1, *sum2;
//     int* sum_first_half;
//     int* sum_second_half;

//     pthread_join(thread1, &sum1);
//     pthread_join(thread2, &sum2);

//     sum_first_half = (int*)sum1;
//     sum_second_half = (int*)sum2;

//     cout<<"Sum of first half: "<<*sum_first_half<<endl;
//     cout<<"Sum of second half: "<<*sum_second_half<<endl;
//     cout<<"Total sum: "<<*sum_first_half+*sum_second_half<<endl;

//     delete sum_first_half;
//     delete sum_second_half;
// }




#include <iostream>
#include <thread>
#include <vector>

using namespace std;

// Function to calculate partial sum of a vector from start to end indices
void partial_sum(const vector<int>& arr, int start, int end, int& result) {
    result = 0;
    for (int i = start; i < end; ++i) {
        result += arr[i];
    }
}

int main() {
    vector<int> arr(20);
    for (int i = 0; i < 20; ++i) {
        arr[i] = i + 1;  // Fill array with 1..20
    }

    int n = arr.size();

    int sum_first_half = 0;
    int sum_second_half = 0;

    // Create two threads to compute partial sums
    thread t1(partial_sum, cref(arr), 0, n / 2, ref(sum_first_half));
    thread t2(partial_sum, cref(arr), n / 2, n, ref(sum_second_half));

    // Wait for threads to finish
    t1.join();
    t2.join();

    cout << "Sum of first half: " << sum_first_half << endl;
    cout << "Sum of second half: " << sum_second_half << endl;
    cout << "Total sum: " << sum_first_half + sum_second_half << endl;

    return 0;
}
